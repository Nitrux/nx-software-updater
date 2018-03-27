#include <QDebug>
#include <QtConcurrent/QtConcurrent>

#include "updateviewcontroller.h"
#include "../interactors/updateinteractor.h"
#include "../entities/packagemanager.h"

UpdateViewController::UpdateViewController(PackageManager* packageManager) {
  this->packageManager = packageManager;
}
UpdateViewController::~UpdateViewController() {}

void UpdateViewController::doUpdate() {
  qDebug() << "Update clicked....";

  UpdateInteractor* updateInteractor =
      new UpdateInteractor(this->packageManager, this);

  QtConcurrent::run([=]() { updateInteractor->execute(); });
}

void UpdateViewController::onUpdateComplete() {
  emit updateComplete();
}
