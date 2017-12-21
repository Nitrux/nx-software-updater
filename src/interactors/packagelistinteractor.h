#ifndef INTERACTORS_PACKAGELISTINTERACTOR_H
#define INTERACTORS_PACKAGELISTINTERACTOR_H

#include "interactor.h"
#include "../helpers/apthelper.h"
#include "../listeners/packagelistlistener.h"

class PackageListInteractor : public Interactor {
 private:
  AptHelper* aptHelper;
  PackageListListener* packageListListener;

 public:
  PackageListInteractor(AptHelper* aptHelper, PackageListListener* listener);
  virtual ~PackageListInteractor();

  void execute();
};

#endif
