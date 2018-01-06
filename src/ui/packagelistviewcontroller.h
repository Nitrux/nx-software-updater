#ifndef UI_PACKAGELISTVIEWCONTROLLER_H
#define UI_PACKAGELISTVIEWCONTROLLER_H

#include <QList>
#include <QVariant>
#include <QVariantList>

#include "../entities/packagemanager.h"
#include "../dto/packagedto.h"
#include "../listeners/packagelistlistener.h"
#include "viewcontroller.h"

class PackageListViewController : public ViewController,
                                  public PackageListListener {
  Q_OBJECT

 public:
  PackageListViewController(PackageManager* packageManager);
  virtual ~PackageListViewController();

 protected:
  virtual void onPackageListReady(QList<PackageDTO*> packageList);

 private:
  PackageManager* packageManager;

 public slots:
  void fetchPackageList();

 signals:
  void packageListChanged(QVariantList packageList);
};

#endif
