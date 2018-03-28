#ifndef ENTITIES_NXI_H
#define ENTITIES_NXI_H

#include "packagemanager.h"
#include "../dto/packagedto.h"
#include "../helpers/nxihelper.h"
#include "../listeners/packagelistlistener.h"
#include "../listeners/updatelistener.h"
#include "../listeners/upgradelistener.h"

class Nxi : public PackageManager {
  Q_OBJECT

 private:
  QList<PackageDTO*> packageList;
  NxiHelper* nxiHelper;
  PackageListListener* packageListListener = nullptr;
  UpdateListener* updateListener = nullptr;
  UpgradeListener* upgradeListener = nullptr;

 public:
  Nxi();
  virtual ~Nxi();

  virtual void getPackageList(PackageListListener* listener) override;
  virtual void update(UpdateListener* listener) override;
  virtual void upgrade(UpgradeListener* listener) override;

 public slots:
  void onNxiListComplete(QList<PackageDTO*> packageList);
  void onNxiUpdateComplete();
  void onNxiUpgradeComplete();

 signals:
  void runNxiList();
  void runNxiUpdate();
  void runNxiUpgrade();
};

#endif
