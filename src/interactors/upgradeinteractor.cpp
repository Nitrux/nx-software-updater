#include "upgradeinteractor.h"
#include "../listeners/updatelistener.h"

UpgradeInteractor::UpgradeInteractor(AptHelper* aptHelper,
                                     UpgradeListener* listener) {
  this->aptHelper = aptHelper;
  this->listener = listener;
}
UpgradeInteractor::~UpgradeInteractor() {}

void UpgradeInteractor::execute() {
  this->aptHelper->aptUpgrade();
  this->listener->onUpgradeComplete();
}
