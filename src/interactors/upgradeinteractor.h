#ifndef INTERACTORS_UPGRADEINTERACTOR_H
#define INTERACTORS_UPGRADEINTERACTOR_H

#include "../helpers/apthelper.h"
#include "../listeners/upgradelistener.h"
#include "interactor.h"

class UpgradeInteractor : public Interactor {
 private:
  AptHelper* aptHelper;
  UpgradeListener* listener;

 public:
  UpgradeInteractor(AptHelper* aptHelper, UpgradeListener* listener);
  virtual ~UpgradeInteractor();

  void execute();
};

#endif
