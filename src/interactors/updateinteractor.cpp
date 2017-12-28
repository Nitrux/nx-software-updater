#include <QDebug>

#include "updateinteractor.h"
#include "../listeners/updatelistener.h"

UpdateInteractor::UpdateInteractor(AptHelper* aptHelper,
                                   UpdateListener* listener) {
  this->aptHelper = aptHelper;
  this->listener = listener;

  connect(this, SIGNAL(runAptUpdate()), this->aptHelper,
          SLOT(onRunAptUpdate()));
  connect(this->aptHelper, SIGNAL(onAptUpdateComplete()), this,
          SLOT(onAptUpdateComplete()));
}
UpdateInteractor::~UpdateInteractor() {}

void UpdateInteractor::execute() {
  //  this->aptHelper->aptUpdate();
  //  this->listener->onUpdateComplete();

  emit runAptUpdate();
}

void UpdateInteractor::onAptUpdateComplete() {
  this->listener->onUpdateComplete();
}
