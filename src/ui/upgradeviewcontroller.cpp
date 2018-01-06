#include <QDebug>
#include <QtConcurrent/QtConcurrent>

#include "upgradeviewcontroller.h"
#include "../interactors/upgradeinteractor.h"
#include "../entities/packagemanager.h"

UpgradeViewController::UpgradeViewController(PackageManager* packageManager) {
  this->packageManager = packageManager;
}
UpgradeViewController::~UpgradeViewController() {}

void UpgradeViewController::doUpgrade() {
  qDebug() << "Upgrade clicked....";

  UpgradeInteractor* upgradeInteractor =
      new UpgradeInteractor(this->packageManager, this);

  QtConcurrent::run([=]() { upgradeInteractor->execute(); });
  //  updateInteractor->execute();
}

void UpgradeViewController::onUpgradeComplete() {
  emit upgradeComplete();
}
