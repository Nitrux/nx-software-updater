#include <QObject>
#include <QDebug>
#include <QThread>
#include <kauth.h>
#include <string>

#include "rootshellkauthhelper.h"

using namespace KAuth;
using namespace std;

RootShellKauthHelper::RootShellKauthHelper(QObject* parent) : QObject(parent) {}
RootShellKauthHelper::~RootShellKauthHelper() {}

ActionReply RootShellKauthHelper::runcommand(QVariantMap args) {
  ActionReply reply;

  qInfo() << ">>>> Running Command : "
          << args["cmd"].toString().toStdString().c_str();

  WorkerThread* workerThread =
      new WorkerThread(this, args["cmd"].toString().toStdString());
  connect(workerThread, &WorkerThread::resultReady, this,
          &RootShellKauthHelper::handleResults);
  connect(workerThread, &WorkerThread::finished, workerThread,
          &QObject::deleteLater);
  workerThread->start();

  workerThread->wait();

  //  while (!this->isCompleted) {
  //    //      if (HelperSupport::isStopped()) {
  //    //        reply.addData("returnVal", -1);
  //    //        return reply;
  //    //      }
  //  }

  qInfo() << "Replying with status";

  reply.addData("returnVal", WEXITSTATUS(this->status));

  return reply;
}

void RootShellKauthHelper::handleResults(int status) {
  qInfo() << "Thread complete handler : " << status;

  this->isCompleted = true;
  this->status = status;
}

WorkerThread::WorkerThread(QObject* parent = nullptr, string cmd = "")
    : QThread(parent) {
  this->cmd = cmd;
}

void WorkerThread::run() {
  qInfo() << "Starting run() : " << this->cmd.c_str();

  int status = system(this->cmd.c_str());

  qInfo() << "run() complete";

  emit resultReady(status);
}

KAUTH_HELPER_MAIN("org.nxos.softwareupdater", RootShellKauthHelper)
