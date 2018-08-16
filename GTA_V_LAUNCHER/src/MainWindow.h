#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QProcess>
#include <QPushButton>
#include "Window.h"
#include "ChooseModsWindow.h"
#include "SettingsWindow.h"
#include <QCloseEvent>
#include <QNetworkReply>
#include <network/Downloader.h>

namespace Ui{
class MainWindow;
}

class MainWindow : public Window{

	Q_OBJECT

	public:
		explicit MainWindow(QWidget* parent = 0);
		~MainWindow();
		void init();
		static QString m_gtaDirectoryStr;
		static QString m_disabledModsDirectoryStr;
		static bool m_launcherCracked;
	private:
		ChooseModsWindow *m_chooseModsWindow = NULL;
		SettingsWindow *m_settingsWindow = NULL;
		Downloader *m_checkGtaVersion;
		Downloader *m_checkSoftwareUpdates;
		void deleteTemp();
		bool isSteamVersion();
		void getGtaVersionThrewInternet();
		bool checkOS();
		void setBackground();
		void closeApp();
		QString getGTAExecutable();
		void setFavicon();
		void setButtons();
		void connectAll();
		void closeEvent(QCloseEvent *event);
		static int getVersionToInt(QString version);
		void removeScriptHookVDinput();
		void addScriptHookVDinput();
		bool checkNeedSteamAndOk();
		bool checkGtaAlreadyStarted(bool showMessage = true);
		Ui::MainWindow* ui;
	public slots:
		void closeAppSlot();
		void startGtaArgsSlot(QStringList args = QStringList());
		void startGtaOnlineSlot();
		void startGtaWithModsSlot(bool offlineMode = false);
		void showChooseModsWindowSlot();
		void downloadFinishedSlot(QByteArray resp);
		void showSettingsWindowSlot();
		void checkSoftwareUpdatesSlot(QByteArray const &resp, bool messageBox = false);
		void getSoftwareUpdates(bool messageBox = false);
		void showPlayContextualMenuSlot(const QPoint &pos);
};

#endif // MAINWINDOW_H
