#include <QDebug>

#include "packagelistinteractor.h"
#include "../listeners/packagelistlistener.h"
#include "../entities/packagemanager.h"

PackageListInteractor::PackageListInteractor(PackageManager* packageManager,
                                             PackageListListener* listener) {
  this->packageManager = packageManager;
  this->listener = listener;
}
PackageListInteractor::~PackageListInteractor() {}

void PackageListInteractor::execute() {
  this->packageManager->getPackageList(this->listener);
}
