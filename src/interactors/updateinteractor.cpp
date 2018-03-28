#include "updateinteractor.h"
#include "../listeners/updatelistener.h"
#include "../entities/packagemanager.h"

UpdateInteractor::UpdateInteractor(PackageManager* packageManager,
                                   UpdateListener* listener) {
  this->packageManager = packageManager;
  this->listener = listener;
}
UpdateInteractor::~UpdateInteractor() {}

void UpdateInteractor::execute() {
  this->packageManager->update(this->listener);
}
