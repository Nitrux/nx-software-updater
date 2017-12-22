#include <QDebug>
#include <QtConcurrent/QtConcurrent>

#include "updateviewcontroller.h"
#include "../interactors/updateinteractor.h"

UpdateViewController::UpdateViewController(AptHelper* aptHelper) {
  this->aptHelper = aptHelper;
}
UpdateViewController::~UpdateViewController() {}

void UpdateViewController::doUpdate() {
  qDebug() << "Update clicked....";

  UpdateInteractor* updateInteractor =
      new UpdateInteractor(this->aptHelper, this);

  QtConcurrent::run([=]() { updateInteractor->execute(); });
}

void UpdateViewController::onUpdateComplete() {
  emit updateComplete();
}
