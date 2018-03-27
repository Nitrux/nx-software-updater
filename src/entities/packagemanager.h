#ifndef ENTITIES_PACKAGEMANAGER_H
#define ENTITIES_PACKAGEMANAGER_H

#include <QList>
#include <QObject>
#include <functional>

#include "../dto/packagedto.h"
#include "../listeners/packagelistlistener.h"
#include "../listeners/updatelistener.h"
#include "../listeners/upgradelistener.h"

using namespace std;

enum PackageManagerType { APT, PACMAN, NXI, OTHER };

class PackageManager : public QObject {
 public:
  PackageManager(QObject* parent = nullptr);
  virtual ~PackageManager();

  static PackageManagerType getPackageManagerType();

  virtual void getPackageList(PackageListListener* listener) = 0;
  virtual void update(UpdateListener* listener) = 0;
  virtual void upgrade(UpgradeListener* listener) = 0;
};

#endif
