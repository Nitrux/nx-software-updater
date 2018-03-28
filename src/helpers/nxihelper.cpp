#include <QDebug>
#include <QFile>
#include <QStandardPaths>
#include <string>
#include <regex>
#include <functional>

#include "nxihelper.h"
#include "../dto/packagedto.h"
#include "../listeners/packagelistlistener.h"

using namespace std;

NxiHelper::NxiHelper(QObject* parent) : QObject(parent) {
  this->storageBasePath =
      QStandardPaths::writableLocation(QStandardPaths::GenericCacheLocation)
          .toStdString() +
      "/nx-software-updater/";
  this->shellHelper = new ShellHelper();

  function<void(int)> lambda = [=](int returnVal) {};

  this->shellHelper->runCommand("mkdir -p " + this->storageBasePath, lambda);
}
NxiHelper::~NxiHelper() {}

void NxiHelper::nxiList(function<void(int)> lambda) {
  QList<PackageDTO*> packageList;
  string line,
      upgradablePackagesListPath = this->storageBasePath + "upgradable",
      cmd = "nxi list --upgradable > " + upgradablePackagesListPath;

  qDebug() << ">>>> Updating list";
  /**
    * Read List of Upgradable packages from nxi-get and store in temporary file
    */
  this->shellHelper->runCommand(cmd, lambda);
}

void NxiHelper::nxiUpdate(function<void(int)> lambda) {
  string cmd =
      "nxi update --assume-yes > " + this->storageBasePath + "update-output";

  this->shellHelper->runCommand(cmd, lambda);
}

void NxiHelper::nxiUpgrade(function<void(int)> lambda) {
  string cmd =
      "nxi upgrade --assume-yes > " + this->storageBasePath + "upgrade-output";

  this->shellHelper->runCommand(cmd, lambda);
}

QList<PackageDTO*> NxiHelper::parsePackageListFile(string path) {
  QList<PackageDTO*> packageList;

  QFile file(path.c_str());
  QTextStream fileInputStream(&file);
  regex packageRegex(
      R"(([\w\-\d\.~:\+]+)\/[\w\-\d\.~:\+,]+\s([\w\-\d\.~:\+]+)\s[\w\-\d\.~:\+]+\s\[upgradable from: ([\w\-\d\.~:\+]+))",
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

void NxiHelper::onRunNxiList() {
  string upgradablePackagesListPath = this->storageBasePath + "upgradable";
  auto that = this;

  function<void(int)> lambda = [=](int returnVal) {
    QList<PackageDTO*> packageList;
    packageList = that->parsePackageListFile(upgradablePackagesListPath);
    emit onNxiListComplete(packageList);
  };

  this->nxiList(lambda);
}

void NxiHelper::onRunNxiUpdate() {
  function<void(int)> lambda = [=](int returnVal) {
    emit onNxiUpdateComplete();
  };

  this->nxiUpdate(lambda);
}

void NxiHelper::onRunNxiUpgrade() {
  function<void(int)> lambda = [=](int returnVal) {
    emit onNxiUpgradeComplete();
  };
  this->nxiUpgrade(lambda);
}
