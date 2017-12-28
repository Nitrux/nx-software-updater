#include <QDebug>
#include <QtConcurrent/QtConcurrent>

#include "upgradeviewcontroller.h"
#include "../interactors/upgradeinteractor.h"

UpgradeViewController::UpgradeViewController(AptHelper* aptHelper) {
  this->aptHelper = aptHelper;
}
UpgradeViewController::~UpgradeViewController() {}

void UpgradeViewController::doUpgrade() {
  qDebug() << "Upgrade clicked....";

  UpgradeInteractor* upgradeInteractor =
      new UpgradeInteractor(this->aptHelper, this);

  QtConcurrent::run([=]() { upgradeInteractor->execute(); });
  //  updateInteractor->execute();
}

void UpgradeViewController::onUpgradeComplete() {
  emit upgradeComplete();
}
