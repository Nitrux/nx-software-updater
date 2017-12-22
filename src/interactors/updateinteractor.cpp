#include "updateinteractor.h"
#include "../listeners/updatelistener.h"

UpdateInteractor::UpdateInteractor(AptHelper* aptHelper,
                                   UpdateListener* listener) {
  this->aptHelper = aptHelper;
  this->listener = listener;
}
UpdateInteractor::~UpdateInteractor() {}

void UpdateInteractor::execute() {
  this->aptHelper->aptUpdate();
  this->listener->onUpdateComplete();
}
