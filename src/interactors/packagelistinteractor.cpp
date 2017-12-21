#include "packagelistinteractor.h"
#include "../listeners/packagelistlistener.h"
#include "../helpers/apthelper.h"

PackageListInteractor::PackageListInteractor(AptHelper* aptHelper,
                                             PackageListListener* listener) {
  this->aptHelper = aptHelper;
  this->packageListListener = packageListListener;
}
PackageListInteractor::~PackageListInteractor() {}

void PackageListInteractor::execute() {
  this->aptHelper->aptUpdate();
  this->packageListListener->onPackageListChanged(this->aptHelper->aptList());
}
