#include <QDebug>
#include <string>
#include <kauth.h>
#include <KAuth>

#include "shellhelper.h"

using namespace std;
using namespace KAuth;

ShellHelper::ShellHelper() {}
ShellHelper::~ShellHelper() {}

int ShellHelper::runCommand(string cmd) {
  Action rootShellAction(QLatin1String("org.nxos.softwareupdater.runcommand"));
  QVariantMap args;
  ExecuteJob* job;

  qDebug() << ">>>> Executing command : " << cmd.c_str();

  args["cmd"] = cmd.c_str();
  rootShellAction.setArguments(args);
  rootShellAction.setHelperId("org.nxos.softwareupdater");
  job = rootShellAction.execute();

  bool execSuccess = job->exec();

  qDebug() << "#### job status : " << job->errorString() << ", "
           << job->errorText();

  if (execSuccess) {
    qDebug() << ">>>> Root Shell Command Success...";
  } else {
    qDebug() << "#### Root Shell Command ERROR!!!!";
  }

  return 0;
}

int ShellHelper::runCommandWithSudo(string cmd) {
  return 0;
}
