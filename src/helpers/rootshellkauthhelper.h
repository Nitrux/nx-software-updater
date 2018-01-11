#ifndef HELPERS_ROOTSHELLKAUTHHELPER_H
#define HELPERS_ROOTSHELLKAUTHHELPER_H

#include <QObject>
#include <QThread>
#include <kauth.h>
#include <string>

using namespace KAuth;
using namespace std;

class RootShellKauthHelper : public QObject {
  Q_OBJECT

 public:
  RootShellKauthHelper(QObject* parent = nullptr);
  virtual ~RootShellKauthHelper();

 private:
  bool isCompleted = false;
  int status;

 public slots:
  ActionReply runcommand(QVariantMap args);
  void handleResults(int status);
};

class WorkerThread : public QThread {
  Q_OBJECT

 public:
  WorkerThread(QObject* parent, string cmd);
  void run() override;

 private:
  string cmd;

 signals:
  void resultReady(int status);
};

#endif
