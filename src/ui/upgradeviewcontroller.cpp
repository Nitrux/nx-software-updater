#include <QDebug>
#include <QtConcurrent/QtConcurrent>

#include "upgradeviewcontroller.h"
#include "../interactors/upgradeinteractor.h"

UpgradeViewController::UpgradeViewController(AptHelper* aptHelper) {
  this->aptHelper = aptHelper;
}
UpgradeViewController::~UpgradeViewController() {}

void UpgradeViewController::doUpgrade() {
  qDebug() << "Update clicked....";

  UpgradeInteractor* updateInteractor =
      new UpgradeInteractor(this->aptHelper, this);

  QtConcurrent::run([=]() { updateInteractor->execute(); });
}

void UpgradeViewController::onUpgradeComplete() {
  emit upgradeComplete();
}
