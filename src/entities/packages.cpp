#include "packages.h"
#include "../dto/packagedto.h"

Packages::Packages(AptHelper* aptHelper) {
  this->aptHelper = aptHelper;
}
Packages::~Packages() {}

QList<PackageDTO> Packages::fetchListOfPackages() {}
