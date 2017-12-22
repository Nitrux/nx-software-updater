#include <QDebug>

#include "packagelistinteractor.h"
#include "../listeners/packagelistlistener.h"
#include "../helpers/apthelper.h"

PackageListInteractor::PackageListInteractor(
    AptHelper* aptHelper,
    PackageListViewController* viewController) {
  this->aptHelper = aptHelper;
  this->viewController = viewController;
}
PackageListInteractor::~PackageListInteractor() {}

void PackageListInteractor::execute() {
  QList<PackageDTO*> packageList;

  packageList = this->aptHelper->aptList();

  this->viewController->onPackageListReady(&packageList);
}
