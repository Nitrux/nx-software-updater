
#ifndef HELPERS_APTHELPER_H
#define HELPERS_APTHELPER_H

#include <QList>
#include <string>

#include "../dto/packagedto.h"

class AptHelper {
 public:
  AptHelper();
  virtual ~AptHelper();

  QList<PackageDTO*> aptList();
  void aptUpdate();
  void aptUpgrade();

 private:
  QList<PackageDTO*> parsePackageListFile(std::string path);
};

#endif
