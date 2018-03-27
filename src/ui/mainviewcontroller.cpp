#include <QDebug>
#include <QMenu>
#include <QAction>
#include <QSystemTrayIcon>
#include <QCoreApplication>
#include <QGuiApplication>

#include "mainviewcontroller.h"
#include "../interactors/quitinteractor.h"

MainViewController::MainViewController() {
  this->trayIcon = new QSystemTrayIcon();
  connect(this->trayIcon, &QSystemTrayIcon::activated, this, [=]() {
    this->trayIcon->hide();
    emit showWindow();
  });

  this->trayIcon->hide();
}
MainViewController::~MainViewController() {}

void MainViewController::showTray() {
  this->trayIcon->show();
}
