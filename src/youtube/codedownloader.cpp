/*  smplayer, GUI front-end for mplayer.
    Copyright (C) 2006-2013 Ricardo Villalba <rvm@users.sourceforge.net>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "codedownloader.h"
#include <QFile>
#include <QMessageBox>

CodeDownloader::CodeDownloader(QWidget *parent) : QProgressDialog(parent)
{
	reply = 0;
	manager = new QNetworkAccessManager(this);
	connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(gotResponse(QNetworkReply*)));

	setMinimumDuration(0);
	setRange(0,100);

	connect(this, SIGNAL(canceled()), this, SLOT(cancelDownload()));
	connect(this, SIGNAL(fileSaved(const QString &)), this, SLOT(reportfileSaved(const QString &)));
	connect(this, SIGNAL(errorOcurred(int,QString)), this, SLOT(reportError(int,QString)));

	setWindowTitle(tr("Downloading..."));
}

CodeDownloader::~CodeDownloader() {
	delete manager;
}

void CodeDownloader::setProxy(QNetworkProxy proxy) {
	manager->setProxy(proxy);

	qDebug("CodeDownloader::setProxy: host: '%s' port: %d type: %d",
           proxy.hostName().toUtf8().constData(), proxy.port(), proxy.type());
}

void CodeDownloader::download(QUrl url) {
	QNetworkRequest req(url);
	reply = manager->get(req);
	connect(reply, SIGNAL(downloadProgress(qint64, qint64)),
            this, SLOT(updateDataReadProgress(qint64, qint64)));

	setLabelText(tr("Downloading %1").arg(url.toString()));
}

void CodeDownloader::cancelDownload() {
	if (reply) reply->abort();
}

void CodeDownloader::gotResponse(QNetworkReply* reply) {
	if (reply->error() == QNetworkReply::NoError) {
		int status = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
		qDebug("CodeDownloader::gotResponse: status: %d", status);
		switch (status) {
			case 301:
			case 302:
			case 307:
				QString r_url = reply->attribute(QNetworkRequest::RedirectionTargetAttribute).toUrl().toString();
				qDebug("CodeDownloader::gotResponse: redirected: %s", r_url.toLatin1().constData());
				download(r_url);
				return;
		}
	} else {
		emit errorOcurred((int)reply->error(), reply->errorString());
		return;
	}

	emit downloadFinished();
	save(reply->readAll());
}

void CodeDownloader::save(QByteArray bytes) {
	if (output_filename.isEmpty()) {
		qWarning("CodeDownloader::save: output filename is empty");
		emit saveFailed(output_filename);
		return;
	}

	QFile file(output_filename);
	if (!file.open(QIODevice::WriteOnly))  {
		qWarning("CodeDownloader::save: could not open %s for writing", output_filename.toUtf8().constData());
		emit saveFailed(output_filename);
		return;
	}

	file.write(bytes);
	file.close();

	reset();
	emit fileSaved(output_filename);
}

void CodeDownloader::updateDataReadProgress(qint64 bytes_read, qint64 total_bytes) {
	setMaximum(total_bytes);
	setValue(bytes_read);
}

void CodeDownloader::reportfileSaved(const QString &) {
	reset();
	QMessageBox::information(this, tr("Success"), tr("The Youtube code has been saved successfully."));
}

void CodeDownloader::reportError(int, QString error_str) {
	reset();
	QMessageBox::warning(this, tr("Error"), tr("An error happened while downloading the file:<br>%1.").arg(error_str));
}

#include "moc_codedownloader.cpp"

