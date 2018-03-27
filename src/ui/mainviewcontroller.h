#ifndef UI_MAINCONTROLLER_H
#define UI_MAINCONTROLLER_H

#include <QCoreApplication>
#include <QSystemTrayIcon>

#include "viewcontroller.h"

class MainViewController : public ViewController {
  Q_OBJECT

 public:
  MainViewController();
  virtual ~MainViewController();

 private:
  QSystemTrayIcon* trayIcon;

 public slots:
  void showTray();

 signals:
  void showWindow();
};

#endif
