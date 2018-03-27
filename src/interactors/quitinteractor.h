#ifndef INTERACTORS_QUITINTERACTOR_H
#define INTERACTORS_QUITINTERACTOR_H

#include "interactor.h"
#include "../listeners/upgradelistener.h"
#include "../entities/packagemanager.h"

class QuitInteractor : public Interactor {
 public:
  QuitInteractor();
  virtual ~QuitInteractor();

  void execute() override;
};

#endif
