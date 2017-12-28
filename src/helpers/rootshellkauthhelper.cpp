#include <QObject>
#include <QDebug>
#include <kauth.h>

#include "rootshellkauthhelper.h"

using namespace KAuth;

RootShellKauthHelper::RootShellKauthHelper(QObject* parent) : QObject(parent) {}
RootShellKauthHelper::~RootShellKauthHelper() {}

ActionReply RootShellKauthHelper::runcommand(QVariantMap args) {
  ActionReply reply;

  int returnVal = system(args["cmd"].toString().toStdString().c_str());

  reply.addData("returnVal", returnVal);

  return reply;
}

KAUTH_HELPER_MAIN("org.nxos.softwareupdater", RootShellKauthHelper)
