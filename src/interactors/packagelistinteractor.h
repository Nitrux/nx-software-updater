#ifndef INTERACTORS_PACKAGELISTINTERACTOR_H
#define INTERACTORS_PACKAGELISTINTERACTOR_H

#include "interactor.h"
#include "../helpers/apthelper.h"
#include "../ui/packagelistviewcontroller.h"

class PackageListInteractor : public Interactor {
 private:
  AptHelper* aptHelper;
  PackageListViewController* viewController;

 public:
  PackageListInteractor(AptHelper* aptHelper,
                        PackageListViewController* viewController);
  virtual ~PackageListInteractor();

  void execute();
};

#endif
