#include <QDebug>
#include <QFile>
#include <string>
#include <regex>

#include "apthelper.h"
#include "../dto/packagedto.h"

using namespace std;

AptHelper::AptHelper() {
  this->shellHelper = new ShellHelper();
}
AptHelper::~AptHelper() {}

QList<PackageDTO*> AptHelper::aptList() {
  QList<PackageDTO*> packageList;
  string line,
      upgradablePackagesListPath =
          "/home/anupam/.nx-software-updater/upgradable",
      cmd = "rm -r " + upgradablePackagesListPath + " && touch " +
            upgradablePackagesListPath + " && apt-get --just-print upgrade > " +
            upgradablePackagesListPath;
  /**
    * Read List of Upgradable packages from apt-get and store in temporary file
    */
  this->shellHelper->runCommand(cmd);

  return this->parsePackageListFile(upgradablePackagesListPath);
}

void AptHelper::aptUpdate() {
  string cmd =
      "apt-get update --assume-yes > "
      "/home/anupam/.nx-software-updater/update-output";

  this->shellHelper->runCommand(cmd);
}

void AptHelper::aptUpgrade() {
  string cmd =
      "apt-get updgrade --assume-no > "
      "/home/anupam/.nx-software-updater/upgrade-output";

  this->shellHelper->runCommand(cmd);
}

QList<PackageDTO*> AptHelper::parsePackageListFile(string path) {
  QList<PackageDTO*> packageList;

  QFile file(path.c_str());
  QTextStream fileInputStream(&file);
  regex packageRegex(
      R"(Inst\s([\w\-\d\.~:\+]+)\s\[([\w\-\d\.~:\+]+)\]\s\(([\w\-\d\.~:\+]+)\)? )",
      regex_constants::icase);

  if (!file.open(QIODevice::ReadOnly)) {
    qDebug() << file.errorString();
  }

  while (!fileInputStream.atEnd()) {
    QString qline = fileInputStream.readLine();
    string line = qline.toUtf8().constData();
    cmatch packageMatchArray;

    regex_search(line.c_str(), packageMatchArray, packageRegex,
                 regex_constants::match_default);

    if (packageMatchArray.size() > 0) {
      string packageName = packageMatchArray[1];

      packageList.append(new PackageDTO(packageName.c_str()));
    }
  }

  file.close();

  return packageList;
}
