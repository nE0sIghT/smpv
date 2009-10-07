;;
;;  italian.nsh
;;
;;  Italian language strings for the Windows SMPlayer NSIS installer.
;;  Save file with UTF-16LE/UCS-2 Little Endian encoding
;;

; Startup
LangString SMPLAYER_INSTALLER_IS_RUNNING ${LANG_ITALIAN} "Il programma di installazione è già in esecuzione."
LangString SMPLAYER_INSTALLER_PREV_ALL_USERS ${LANG_ITALIAN} "SMPlayer has been previously installed for all users.$\nPlease restart the installer with Administrator privileges."
LangString SMPLAYER_INSTALLER_PREV_VERSION ${LANG_ITALIAN} "SMPlayer è già stato installato.$\nVuoi rimuovere la versione precedente prima dell'installazione di $(^Name)?"

; Components Page
LangString MPLAYER_CODEC_INFORMATION ${LANG_ITALIAN} "I pacchetti di codec binari forniscono il supporto per i codec che non sono stati ancora implementati nativamente, per esempio per le varianti di RealVideo e anche un sacco di formati poco utilizzati.$\nNota che non sono richiesti per riprodurre i formati più comuni come DVD, MPEG-1/2/4, ecc."

; MPlayer Section
LangString MPLAYER_IS_INSTALLED ${LANG_ITALIAN} "MPlayer è già stato installato. Ri-scarico?"
LangString MPLAYER_IS_DOWNLOADING ${LANG_ITALIAN} "Sto scaricando MPlayer..."
LangString MPLAYER_DL_FAILED ${LANG_ITALIAN} "Scaricamento di MPlayer fallito:"
LangString MPLAYER_INST_FAILED ${LANG_ITALIAN} "Installazione di MPlayer fallita. MPlayer è un componente necessario per la riproduzione multimediale."

; Codecs Section
LangString CODECS_IS_INSTALLED ${LANG_ITALIAN} "I codec di MPlayer sono già stati installati. Ri-scarico?"
LangString CODECS_IS_DOWNLOADING ${LANG_ITALIAN} "Sto scaricando i codec di MPlayer..."
LangString CODECS_DL_FAILED ${LANG_ITALIAN} "Scaricamento dei codec di MPlayer fallito:"
LangString CODECS_INST_FAILED ${LANG_ITALIAN} "Installazione dei codec di MPlayer fallita."

; Version information
LangString VERINFO_IS_DOWNLOADING ${LANG_ITALIAN} "Sto scaricando le informazioni di versione..."
LangString VERINFO_DL_FAILED ${LANG_ITALIAN} "Scaricamento delle informazioni di versione fallito:"
LangString VERINFO_IS_MISSING ${LANG_ITALIAN} "Il file di versione non contiene informazioni di versione. Verrà utilizzata una versione predefinita."

; Uninstaller
LangString UNINSTALL_ABORTED ${LANG_ITALIAN} "Uninstall aborted by user."
LangString UNINSTALL_INSTALLED_ALL_USERS ${LANG_ITALIAN} "SMPlayer has been installed for all users.$\nPlease restart the uninstaller with Administrator privileges to remove it."
LangString SMPLAYER_NOT_INSTALLED ${LANG_ITALIAN} "Sembra che SMPlayer non sia installato nel direttorio '$INSTDIR'.$\r$\nContinua comunque (non raccomandato)?"

; Vista & Later Default Programs Registration
LangString APPLICATION_DESCRIPTION ${LANG_ITALIAN} "SMPlayer is a complete front-end for MPlayer, from basic features like playing videos, DVDs, VCDs to more advanced features like support for MPlayer filters, edl lists, and more."
