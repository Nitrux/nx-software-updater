#ifndef UI_UPGRADEVIEWCONTROLLER_H
#define UI_UPGRADEVIEWCONTROLLER_H

#include "viewcontroller.h"
#include "../helpers/apthelper.h"
#include "../listeners/upgradelistener.h"

class UpgradeViewController : public ViewController, UpgradeListener {
  Q_OBJECT

 private:
  AptHelper* aptHelper;

 public:
  UpgradeViewController(AptHelper* aptHelper);
  virtual ~UpgradeViewController();

 protected:
  virtual void onUpgradeComplete();

 public slots:
  void doUpgrade();

 signals:
  void upgradeComplete();
};

#endif
