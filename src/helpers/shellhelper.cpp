#include <QDebug>
#include <QObject>
#include <QTimer>
#include <string>
#include <kauth.h>
#include <KAuth>
#include <functional>

#include "shellhelper.h"

using namespace std;
using namespace KAuth;

ShellHelper::ShellHelper(QObject* parent) : QObject(parent) {}
ShellHelper::~ShellHelper() {}

void ShellHelper::runCommand(string cmd, function<void(int)> lambda) {
  Action rootShellAction(QLatin1String("org.nxos.softwareupdater.runcommand"));
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

  connect(job, &ExecuteJob::result, this, [=](KJob* resultJob) {
    ExecuteJob* job = (ExecuteJob*)resultJob;
    //    bool execSuccess = job->exec();

    //    qDebug() << "#### job status : " << job->errorString() << ", "
    //             << job->errorText()
    //             << ", returnVal : " << job->data()["returnVal"].toString();

    //    if (execSuccess) {
    //      qDebug() << ">>>> Root Shell Command Success...";
    //    } else {
    //      qDebug() << "#### Root Shell Command ERROR!!!!";
    //    }

    lambda(job->data()["returnVal"].toInt());
  });

  job->start();
}
