#ifndef INTERACTORS_PACKAGELISTINTERACTOR_H
#define INTERACTORS_PACKAGELISTINTERACTOR_H

#include "interactor.h"
#include "../listeners/packagelistlistener.h"
#include "../entities/packagemanager.h"

class PackageListInteractor : public Interactor {
  Q_OBJECT

 private:
  PackageManager* packageManager;
  PackageListListener* listener;

 public:
  PackageListInteractor(PackageManager* packageManager,
                        PackageListListener* viewController);
  virtual ~PackageListInteractor();

  void execute();
};

#endif
