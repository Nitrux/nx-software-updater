#include "upgradeinteractor.h"
#include "../listeners/upgradelistener.h"
#include "../entities/packagemanager.h"

UpgradeInteractor::UpgradeInteractor(PackageManager* packageManager,
                                     UpgradeListener* listener) {
  this->packageManager = packageManager;
  this->listener = listener;
}
UpgradeInteractor::~UpgradeInteractor() {}

void UpgradeInteractor::execute() {
  this->packageManager->upgrade(this->listener);
}
