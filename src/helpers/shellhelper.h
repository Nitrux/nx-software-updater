#ifndef HELPERS_SHELLHELPER_H
#define HELPERS_SHELLHELPER_H

#include <QObject>
#include <functional>
#include <string>

#include "../listeners/packagelistlistener.h"

using namespace std;

class ShellHelper : QObject {
  Q_OBJECT

 public:
  ShellHelper(QObject* parent = nullptr);
  virtual ~ShellHelper();

  void runCommand(string cmd, function<void()> lambda);
};

#endif
