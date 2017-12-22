#ifndef HELPERS_SHELLHELPER_H
#define HELPERS_SHELLHELPER_H

#include <string>

using namespace std;

class ShellHelper {
 public:
  ShellHelper();
  virtual ~ShellHelper();

  int runCommand(string cmd);
  int runCommandWithSudo(string cmd);
};

#endif
