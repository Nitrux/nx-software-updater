#ifndef INTERACTORS_UPDATEINTERACTOR_H
#define INTERACTORS_UPDATEINTERACTOR_H

#include "interactor.h"
#include "../listeners/updatelistener.h"
#include "../entities/packagemanager.h"

class UpdateInteractor : public Interactor {
  Q_OBJECT

 private:
  PackageManager* packageManager;
  UpdateListener* listener;

 public:
  UpdateInteractor(PackageManager* packageManager, UpdateListener* listener);
  virtual ~UpdateInteractor();

  void execute();
};

#endif
