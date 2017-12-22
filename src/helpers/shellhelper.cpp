#include <string>

#include "shellhelper.h"

using namespace std;

ShellHelper::ShellHelper() {}
ShellHelper::~ShellHelper() {}

int ShellHelper::runCommand(string cmd) {
  return system(cmd.c_str());
}

int ShellHelper::runCommandWithSudo(string cmd) {}
