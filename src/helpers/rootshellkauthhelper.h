#ifndef HELPERS_ROOTSHELLKAUTHHELPER_H
#define HELPERS_ROOTSHELLKAUTHHELPER_H

#include <QObject>
#include <kauth.h>

using namespace KAuth;

class RootShellKauthHelper : public QObject {
  Q_OBJECT

 public:
  RootShellKauthHelper(QObject* parent = nullptr);
  virtual ~RootShellKauthHelper();

 public slots:
  ActionReply runcommand(QVariantMap args);
};

#endif
