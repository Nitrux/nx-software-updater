#ifndef ENTITIES_PACKAGES_H
#define ENTITIES_PACKAGES_H

#include <QList>
#include <QString>

class Packages {
 public:
  Packages();
  virtual ~Packages();

  QList<QString> fetchListOfPackages();
  int updatePackages();
};

#endif
