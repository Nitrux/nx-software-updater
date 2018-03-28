#include <QDebug>
#include <functional>

#include "packagemanager.h"
#include "../helpers/shellhelper.h"

using namespace std;

PackageManager::PackageManager(QObject* parent) : QObject(parent) {}
PackageManager::~PackageManager() {}

PackageManagerType PackageManager::getPackageManagerType() {
  int status;

  status = system("pacman --version > /dev/null");

  if (WEXITSTATUS(status) == 0) {
    return PackageManagerType::PACMAN;
  } else {
    status = system("apt-get --version > /dev/null");

    if (WEXITSTATUS(status) == 0) {
      return PackageManagerType::APT;
    } else {
      status = system("nxi --version > /dev/null");

      if (WEXITSTATUS(status) == 0) {
        return PackageManagerType::NXI;
      } else {
        return PackageManagerType::OTHER;
      }
    }
  }
}
