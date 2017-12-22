#ifndef LISTENERS_PACKAGELISTLISTENER_H
#define LISTENERS_PACKAGELISTLISTENER_H

#include <QList>

#include "../dto/packagedto.h"

class PackageListListener {
 public:
  virtual ~PackageListListener() {}
  virtual void onPackageListReady(QList<PackageDTO*>* packageList) = 0;
};

#endif
