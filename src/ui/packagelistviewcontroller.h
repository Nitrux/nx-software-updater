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

 private:
  AptHelper* aptHelper;

 public:
  PackageListViewController(AptHelper* aptHelper);
  virtual ~PackageListViewController();

  void onPackageListChanged(QList<PackageDTO> packageList);

 public slots:
  void updateClicked();

 signals:
  void packageListChanged(QVariantList packageList);
};

#endif
