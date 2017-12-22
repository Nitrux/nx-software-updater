#include <QDebug>
#include <fstream>
#include <QFile>
#include <string>
#include <regex>
#include <iostream>

#include "apthelper.h"
#include "../dto/packagedto.h"

using namespace std;

AptHelper::AptHelper() {}
AptHelper::~AptHelper() {}

QList<PackageDTO*> AptHelper::aptList() {
  QList<PackageDTO*> packageList;
  std::string line,
      upgradablePackagesListPath =
          "/home/anupam/.nx-software-updater/upgradable",
      cmd = "rm -r " + upgradablePackagesListPath + " && touch " +
            upgradablePackagesListPath + " && apt-get --just-print upgrade > " +
            upgradablePackagesListPath;
  std::ifstream fileUpgradablePackagesListPath;

  /**
    * Read List of Upgradable packages from apt-get and store in temporary file
    */
  system(cmd.c_str());

  return this->parsePackageListFile(upgradablePackagesListPath);
}

void AptHelper::aptUpdate() {}

void AptHelper::aptUpgrade() {}

QList<PackageDTO*> AptHelper::parsePackageListFile(std::string path) {
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
