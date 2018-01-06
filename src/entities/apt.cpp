#include <QList>
#include "../dto/packagedto.h"

#include "apt.h"

Apt::Apt() {
  this->aptHelper = new AptHelper();

  connect(this, SIGNAL(runAptList()), this->aptHelper, SLOT(onRunAptList()));
  connect(this->aptHelper, SIGNAL(onAptListComplete(QList<PackageDTO*>)), this,
          SLOT(onAptListComplete(QList<PackageDTO*>)));

  connect(this, SIGNAL(runAptUpdate()), this->aptHelper,
          SLOT(onRunAptUpdate()));
  connect(this->aptHelper, SIGNAL(onAptUpdateComplete()), this,
          SLOT(onAptUpdateComplete()));

  connect(this, SIGNAL(runAptUpgrade()), this->aptHelper,
          SLOT(onRunAptUpgrade()));
  connect(this->aptHelper, SIGNAL(onAptUpgradeComplete()), this,
          SLOT(onAptUpgradeComplete()));
}
Apt::~Apt() {}

void Apt::getPackageList(PackageListListener* listener) {
  this->packageListListener = listener;
  emit runAptList();
}

void Apt::update(UpdateListener* listener) {
  this->updateListener = listener;
  emit runAptUpdate();
}

void Apt::upgrade(UpgradeListener* listener) {
  this->upgradeListener = listener;
  emit runAptUpgrade();
}

void Apt::onAptListComplete(QList<PackageDTO*> packageList) {
  if (this->packageListListener != nullptr) {
    this->packageListListener->onPackageListReady(packageList);
  }
}

void Apt::onAptUpdateComplete() {
  if (this->updateListener != nullptr) {
    this->updateListener->onUpdateComplete();
  }
}

void Apt::onAptUpgradeComplete() {
  if (this->upgradeListener != nullptr) {
    this->upgradeListener->onUpgradeComplete();
  }
}
