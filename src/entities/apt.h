#ifndef ENTITIES_APT_H
#define ENTITIES_APT_H

#include "packagemanager.h"
#include "../dto/packagedto.h"
#include "../helpers/apthelper.h"
#include "../listeners/packagelistlistener.h"
#include "../listeners/updatelistener.h"
#include "../listeners/upgradelistener.h"

class Apt : public PackageManager {
  Q_OBJECT

 private:
  QList<PackageDTO*> packageList;
  AptHelper* aptHelper;
  PackageListListener* packageListListener = nullptr;
  UpdateListener* updateListener = nullptr;
  UpgradeListener* upgradeListener = nullptr;

 public:
  Apt();
  virtual ~Apt();

  virtual void getPackageList(PackageListListener* listener) override;
  virtual void update(UpdateListener* listener) override;
  virtual void upgrade(UpgradeListener* listener) override;

 public slots:
  void onAptListComplete(QList<PackageDTO*> packageList);
  void onAptUpdateComplete();
  void onAptUpgradeComplete();

 signals:
  void runAptList();
  void runAptUpdate();
  void runAptUpgrade();
};

#endif
