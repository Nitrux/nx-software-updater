#include <QList>
#include "../dto/packagedto.h"

#include "nxi.h"

Nxi::Nxi() {
  this->nxiHelper = new NxiHelper();

  connect(this, SIGNAL(runNxiList()), this->nxiHelper, SLOT(onRunNxiList()));
  connect(this->nxiHelper, SIGNAL(onNxiListComplete(QList<PackageDTO*>)), this,
          SLOT(onNxiListComplete(QList<PackageDTO*>)));

  connect(this, SIGNAL(runNxiUpdate()), this->nxiHelper,
          SLOT(onRunNxiUpdate()));
  connect(this->nxiHelper, SIGNAL(onNxiUpdateComplete()), this,
          SLOT(onNxiUpdateComplete()));

  connect(this, SIGNAL(runNxiUpgrade()), this->nxiHelper,
          SLOT(onRunNxiUpgrade()));
  connect(this->nxiHelper, SIGNAL(onNxiUpgradeComplete()), this,
          SLOT(onNxiUpgradeComplete()));
}
Nxi::~Nxi() {}

void Nxi::getPackageList(PackageListListener* listener) {
  this->packageListListener = listener;
  emit runNxiList();
}

void Nxi::update(UpdateListener* listener) {
  this->updateListener = listener;
  emit runNxiUpdate();
}

void Nxi::upgrade(UpgradeListener* listener) {
  this->upgradeListener = listener;
  emit runNxiUpgrade();
}

void Nxi::onNxiListComplete(QList<PackageDTO*> packageList) {
  if (this->packageListListener != nullptr) {
    this->packageListListener->onPackageListReady(packageList);
  }
}

void Nxi::onNxiUpdateComplete() {
  if (this->updateListener != nullptr) {
    this->updateListener->onUpdateComplete();
  }
}

void Nxi::onNxiUpgradeComplete() {
  if (this->upgradeListener != nullptr) {
    this->upgradeListener->onUpgradeComplete();
  }
}
