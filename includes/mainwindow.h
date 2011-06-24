#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include "advancedwindow.h"
#include "batchwindow.h"
#include "QAffiche.h"
#include "QBouton.h"
#include "textedit.h"



namespace Ui
{
    class mainWindow;
}

class mainWindow : public QMainWindow
{
    Q_OBJECT

	public:
		explicit mainWindow(QString, QStringList, QMap<QString,QString>);
		~mainWindow();

	public slots:
		// Log
		void log(QString l);
		void logUpdate(QString l);
		void logShow();
		void logClear();
		// Menus
		void options();
		void optionsClosed();
		void help();
		void aboutAuthor();
		void saveFolder();
		// Language
		void switchTranslator(QTranslator&, const QString&);
		void loadLanguage(const QString&, bool shutup = false);
		void changeEvent(QEvent*);
		// Favorites
		void loadFavorite(int);
		void favoriteProperties(int);
		void updateFavorites();
		void viewed();
		void setFavoriteViewed(QString);
		void favoritesBack();
		void checkFavorites();
		void loadNextFavorite();
		// Download
		void webUpdateLast();
		void webUpdateTags();
		void webUpdatePopular();
		void web(QString tags = "", bool popular = false);
		void webZoom(int);
		void replyFinished(QNetworkReply*);
		void replyFinishedPic(QNetworkReply*);
		// Batch download management
		void batchClear();
		void batchChange(int);
		void updateBatchGroups(int, int);
		void addGroup();
		void addUnique();
		void batchAddGroup(const QStringList& values);
		void batchAddUnique(QMap<QString,QString>);
		void getPage();
		// Batch download
		void getAll();
		void getAllPerformTags(QNetworkReply*);
		void getAllPerformImage(QNetworkReply*);
		void getAllCancel();
		void getAllSource(QNetworkReply*);
		void _getAll();
		// Others
		void setTags(QString);
		void closeEvent(QCloseEvent*);
		void advanced();
		void saveAdvanced(advancedWindow*);
		void widgetPlusChange();

	private:
		Ui::mainWindow *ui;
		QSettings *m_settings;
		QDateTime m_serverDate;
		int m_timezonedecay, m_getAllId, m_getAllDownloaded, m_getAllExists, m_getAllIgnored, m_getAllErrors, m_getAllCount, m_getAllPageCount, m_getAllBeforeId, m_pagemax, m_remainingPics, m_remainingSites, m_countPics, m_currentFav, m_currentFavCount;
		QMap<QString,QString> m_favorites, m_params;
		QString m_program;
		QStringList m_tags, m_assoc, m_gotMd5;
		QList<QStringList> m_groupBatchs;
		bool m_allow, m_currentPageIsPopular, m_must_get_tags, m_lastWeb;
		QList<QMap<QString, QString> > m_details, m_batchs, m_allImages;
		QMap<QDateTime,QString> *m_log;
		QString m_currLang;
		QTranslator m_translator;
		QList<bool> m_selected;
		QCalendarWidget *m_calendar;
		QMap<QString,QMap<QString,QString> > m_sites;
		QMap<QString,QStringList> m_getAllDetails;
		QList<QAffiche*> m_favoritesCaptions;
		QList<QBouton*> m_favoritesImages;
		QDateTime m_loadFavorite;
		QString m_currentFavorite;
		QList<QNetworkReply*> m_replies;
		QList<QBouton*> m_webPics;
		QList<QLabel*> m_webSites;
		QMap<QString,int> m_countPage;
		TextEdit *m_search, *m_postFiltering;
		QProcess *m_process;
		QNetworkReply *m_getAllRequest;
		batchWindow *m_progressdialog;
		QList<QBouton*> m_mergeButtons;
};

#endif // MAINWINDOW_H