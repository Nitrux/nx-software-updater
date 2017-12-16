#ifndef ENTITIES_PACKAGES_H
#define ENTITIES_PACKAGES_H

#include <QList>
#include <QString>

#include "../helpers/apthelper.h"
#include "../dto/packagedto.h"

class Packages {
 private:
  AptHelper* aptHelper;

 public:
  Packages(AptHelper* aptHelper);
  virtual ~Packages();

  QList<PackageDTO> fetchListOfPackages();
  int upgradePackages();
};

#endif
