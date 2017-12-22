#ifndef INTERACTORS_PACKAGELISTINTERACTOR_H
#define INTERACTORS_PACKAGELISTINTERACTOR_H

#include "interactor.h"
#include "../helpers/apthelper.h"
#include "../ui/packagelistviewcontroller.h"
#include "../listeners/packagelistlistener.h"

class PackageListInteractor : public Interactor {
 private:
  AptHelper* aptHelper;
  PackageListListener* listener;

 public:
  PackageListInteractor(AptHelper* aptHelper,
                        PackageListListener* viewController);
  virtual ~PackageListInteractor();

  void execute();
};

#endif
