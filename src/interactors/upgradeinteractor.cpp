#include "upgradeinteractor.h"
#include "../listeners/updatelistener.h"

UpgradeInteractor::UpgradeInteractor(AptHelper* aptHelper,
                                     UpgradeListener* listener) {
  this->aptHelper = aptHelper;
  this->listener = listener;

  connect(this, SIGNAL(runAptUpgrade()), this->aptHelper,
          SLOT(onRunAptUpgrade()));
  connect(this->aptHelper, SIGNAL(onAptUpgradeComplete()), this,
          SLOT(onAptUpgradeComplete()));
}
UpgradeInteractor::~UpgradeInteractor() {}

void UpgradeInteractor::execute() {
  //  this->aptHelper->aptUpgrade();
  //  this->listener->onUpgradeComplete();

  emit runAptUpgrade();
}

void UpgradeInteractor::onAptUpgradeComplete() {
  this->listener->onUpgradeComplete();
}
