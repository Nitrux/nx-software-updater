#ifndef INTERACTORS_UPDATEINTERACTOR_H
#define INTERACTORS_UPDATEINTERACTOR_H

#include "../helpers/apthelper.h"
#include "../listeners/updatelistener.h"
#include "interactor.h"

class UpdateInteractor : public Interactor {
 private:
  AptHelper* aptHelper;
  UpdateListener* listener;

 public:
  UpdateInteractor(AptHelper* aptHelper, UpdateListener* listener);
  virtual ~UpdateInteractor();

  void execute();
};

#endif
