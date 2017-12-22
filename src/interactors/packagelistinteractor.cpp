#include <QDebug>

#include "packagelistinteractor.h"
#include "../listeners/packagelistlistener.h"
#include "../helpers/apthelper.h"

PackageListInteractor::PackageListInteractor(AptHelper* aptHelper,
                                             PackageListListener* listener) {
  this->aptHelper = aptHelper;
  this->listener = listener;
}
PackageListInteractor::~PackageListInteractor() {}

void PackageListInteractor::execute() {
  QList<PackageDTO*> packageList;

  packageList = this->aptHelper->aptList();

  this->listener->onPackageListReady(&packageList);
}
