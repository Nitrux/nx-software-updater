#ifndef UI_UPGRADEVIEWCONTROLLER_H
#define UI_UPGRADEVIEWCONTROLLER_H

#include "viewcontroller.h"
#include "../listeners/upgradelistener.h"
#include "../entities/packagemanager.h"

class UpgradeViewController : public ViewController, UpgradeListener {
  Q_OBJECT

 private:
  PackageManager* packageManager;

 public:
  UpgradeViewController(PackageManager* packageManager);
  virtual ~UpgradeViewController();

 protected:
  virtual void onUpgradeComplete();

 public slots:
  void doUpgrade();

 signals:
  void upgradeComplete();
};

#endif
