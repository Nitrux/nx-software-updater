#ifndef HELPERS_SHELLHELPER_H
#define HELPERS_SHELLHELPER_H

#include <string>

#include "../listeners/packagelistlistener.h"

using namespace std;

class ShellHelper {
 public:
  ShellHelper();
  virtual ~ShellHelper();

  int runCommand(string cmd);
  int runCommand(string cmd, PackageListListener* listener);
  int runCommandWithSudo(string cmd);
};

#endif
