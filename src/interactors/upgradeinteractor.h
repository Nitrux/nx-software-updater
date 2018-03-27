#ifndef INTERACTORS_UPGRADEINTERACTOR_H
#define INTERACTORS_UPGRADEINTERACTOR_H

#include "interactor.h"
#include "../listeners/upgradelistener.h"
#include "../entities/packagemanager.h"

class UpgradeInteractor : public Interactor {
  Q_OBJECT

 private:
  PackageManager* packageManager;
  UpgradeListener* listener;

 public:
  UpgradeInteractor(PackageManager* packageManager, UpgradeListener* listener);
  virtual ~UpgradeInteractor();

  void execute();
};

#endif
