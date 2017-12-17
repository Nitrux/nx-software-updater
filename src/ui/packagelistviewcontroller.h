#ifndef UI_PACKAGELISTVIEWCONTROLLER_H
#define UI_PACKAGELISTVIEWCONTROLLER_H

#include <QList>

#include "../dto/packagedto.h"
#include "viewcontroller.h"

class PackageListViewController : public ViewController {
  Q_OBJECT

 public:
  PackageListViewController();
  virtual ~PackageListViewController();

 public slots:
  void updateClicked();

 signals:
  void packageListChanged();
};

#endif
