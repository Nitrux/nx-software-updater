#include <QObject>
#include <QDebug>
#include <time.h>
#include <kauth.h>

#include "rootshellkauthhelper.h"

using namespace KAuth;

RootShellKauthHelper::RootShellKauthHelper(QObject* parent) : QObject(parent) {}
RootShellKauthHelper::~RootShellKauthHelper() {}

ActionReply RootShellKauthHelper::runcommand(QVariantMap args) {
  ActionReply reply;

  int status = system(args["cmd"].toString().toStdString().c_str());

  reply.addData("returnVal", WEXITSTATUS(status));

  return reply;
}

KAUTH_HELPER_MAIN("org.nxos.softwareupdater", RootShellKauthHelper)
