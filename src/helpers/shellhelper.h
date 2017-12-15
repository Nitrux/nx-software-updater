#ifndef HELPERS_SHELLHELPER_H
#define HELPERS_SHELLHELPER_H

#include <QString>

class ShellHelper {
 public:
  ShellHelper();
  virtual ~ShellHelper();

  int runCommand(QString cmd);
  int runCommandWithSudo(QString cmd);
};

#endif
