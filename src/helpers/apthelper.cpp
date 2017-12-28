#include <QDebug>
#include <QFile>
#include <QStandardPaths>
#include <string>
#include <regex>

#include "apthelper.h"
#include "../dto/packagedto.h"
#include "../listeners/packagelistlistener.h"

using namespace std;

AptHelper::AptHelper(QObject* parent) : QObject(parent) {
  this->storageBasePath =
      QStandardPaths::writableLocation(QStandardPaths::GenericCacheLocation)
          .toStdString() +
      "/nx-software-updater/";
  this->shellHelper = new ShellHelper();

  this->shellHelper->runCommand("mkdir -p " + this->storageBasePath);
}
AptHelper::~AptHelper() {}

QList<PackageDTO*> AptHelper::aptList() {
  QList<PackageDTO*> packageList;
  string line,
      upgradablePackagesListPath = this->storageBasePath + "upgradable",
      cmd = "apt-get --just-print upgrade > " + upgradablePackagesListPath;

  qDebug() << ">>>> Updating list";
  /**
    * Read List of Upgradable packages from apt-get and store in temporary file
    */
  this->shellHelper->runCommand(cmd);

  qDebug() << ">>>> Updated";

  qDebug()
      << ">>>> Package List Fetched... Calling listener to parse pacage list";

  packageList = this->parsePackageListFile(upgradablePackagesListPath);

  return packageList;
}

void AptHelper::aptUpdate() {
  string cmd = "apt-get update --assume-yes > " + this->storageBasePath +
               "update-output";

  this->shellHelper->runCommand(cmd);
}

void AptHelper::aptUpgrade() {
  string cmd =
      "PATH=\"$PATH:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/"
      "bin\" apt-get upgrade --assume-yes > " +
      this->storageBasePath + "upgrade-output";

  this->shellHelper->runCommand(cmd);
}

QList<PackageDTO*> AptHelper::parsePackageListFile(string path) {
  QList<PackageDTO*> packageList;

  QFile file(path.c_str());
  QTextStream fileInputStream(&file);
  regex packageRegex(
      R"(Inst\s([\w\-\d\.~:\+]+)\s\[([\w\-\d\.~:\+]+)\]\s\(([\w\-\d\.~:\+]+)\)? )",
      regex_constants::icase);

  qDebug() << "Parsing Package List....";

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

void AptHelper::onRunAptList() {
  QList<PackageDTO*> packageList;

  packageList = this->aptList();
  emit onAptListComplete(packageList);
}

void AptHelper::onRunAptUpdate() {
  this->aptUpdate();
  emit onAptUpdateComplete();
}

void AptHelper::onRunAptUpgrade() {
  this->aptUpgrade();
  emit onAptUpgradeComplete();
}
