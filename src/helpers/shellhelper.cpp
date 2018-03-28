#include <QDebug>
#include <QObject>
#include <QTimer>
#include <string>
#include <kauth.h>
#include <functional>

#include "shellhelper.h"
#include "../actions/actionids.h"

using namespace std;
using namespace KAuth;

ShellHelper::ShellHelper(QObject* parent) : QObject(parent) {}
ShellHelper::~ShellHelper() {}

void ShellHelper::runCommand(string cmd, function<void(int)> lambda) {
  Action rootShellAction(ActionIds::ACTION_RUN_COMMAND);
  QVariantMap args;
  ExecuteJob* job;

  qDebug() << ">>>> Executing command : " << cmd.c_str();

  string _cmd =
      "PATH=\"$PATH:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/"
      "bin\" " +
      cmd;

  args["cmd"] = _cmd.c_str();

  rootShellAction.setArguments(args);
  rootShellAction.setHelperId("org.nxos.softwareupdater");
  rootShellAction.setTimeout(1800000);
  job = rootShellAction.execute();

  job->exec();

  //  connect(job, &ExecuteJob::result, this, [=](KJob* resultJob) {
  //  ExecuteJob* job = (ExecuteJob*)resultJob;

  qDebug() << ">>>> Exit Status : " << job->data()["returnVal"].toInt();

  lambda(job->data()["returnVal"].toInt());
  //  });

  //  job->start();

  //  qDebug() << ">>>> Killing job : " << job->kill();
}
