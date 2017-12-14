#ifndef INTERACTORS_DOWNLOADANDINSTALLINTERACTOR_H
#define INTERACTORS_DOWNLOADANDINSTALLINTERACTOR_H

#include "interactor.h"

class DownloadAndInstallInteractor : public Interactor {
 public:
  DownloadAndInstallInteractor();
  virtual ~DownloadAndInstallInteractor();

  void execute() override;
};

#endif
