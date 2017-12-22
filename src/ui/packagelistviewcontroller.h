#ifndef UI_PACKAGELISTVIEWCONTROLLER_H
#define UI_PACKAGELISTVIEWCONTROLLER_H

#include <QList>
#include <QVariant>
#include <QVariantList>

#include "../dto/packagedto.h"
#include "../helpers/apthelper.h"
#include "../listeners/packagelistlistener.h"
#include "viewcontroller.h"

class PackageListViewController : public ViewController,
                                  public PackageListListener {
  Q_OBJECT

 public:
  PackageListViewController(AptHelper* aptHelper);
  virtual ~PackageListViewController();

 protected:
  virtual void onPackageListReady(QList<PackageDTO*>* packageList);

 private:
  AptHelper* aptHelper;

 public slots:
  void fetchPackageList();

 signals:
  void packageListChanged(QVariantList packageList);
};

#endif
