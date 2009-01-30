/*  smplayer, GUI front-end for mplayer.
    Copyright (C) 2006-2009 Ricardo Villalba <rvm@escomposlinux.org>

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

#include "timedialog.h"

TimeDialog::TimeDialog( QWidget* parent, Qt::WindowFlags f )
	: QDialog(parent, f)
{
	setupUi(this);

	time_edit->setDisplayFormat("H:mm:ss");
}

TimeDialog::~TimeDialog() {
}

void TimeDialog::setTime(int seconds) {
	QTime t;
	time_edit->setTime(t.addSecs(seconds));
}

int TimeDialog::time() {
	QTime t;
	return t.secsTo(time_edit->time());
}

void TimeDialog::setMaximumTime( int seconds ) {
	QTime t;
	time_edit->setMaximumTime(t.addSecs(seconds));
}

int TimeDialog::maximumTime() {
	QTime t;
	return t.secsTo(time_edit->maximumTime());
}

void TimeDialog::setLabel(const QString & label) {
	time_label->setText(label);
}

QString TimeDialog::label() {
	return time_label->text();
}

#include "moc_timedialog.cpp"
