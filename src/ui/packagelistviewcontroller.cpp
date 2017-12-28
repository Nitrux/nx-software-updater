#include <QDebug>
#include <QList>
#include <QVariant>
#include <QVariantList>
#include <QtConcurrent/QtConcurrent>

#include "packagelistviewcontroller.h"
#include "../dto/packagedto.h"
#include "../helpers/apthelper.h"
#include "../interactors/packagelistinteractor.h"

PackageListViewController::PackageListViewController(AptHelper* aptHelper) {
  this->aptHelper = aptHelper;
}
PackageListViewController::~PackageListViewController() {}

void PackageListViewController::fetchPackageList() {
  qDebug() << "Fetching Package List....";

  PackageListInteractor* packageListInteractor =
      new PackageListInteractor(this->aptHelper, this);

  QtConcurrent::run([=]() { packageListInteractor->execute(); });
  //  packageListInteractor->execute();
  qDebug() << "Executed Fetching Package List....";
}

void PackageListViewController::onPackageListReady(
    QList<PackageDTO*>* packageList) {
  QVariantList qvPackageList;

  for (PackageDTO* package : *packageList) {
    QVariantMap packageData;

    packageData["packageName"] = package->getPackageName();
    packageData["description"] = package->getDescription();
    packageData["iconUrl"] = package->getIconUrl();
    packageData["size"] = package->getSize();
    packageData["version"] = package->getVersion();

    qvPackageList.append(packageData);
  }

  emit packageListChanged(qvPackageList);
}
