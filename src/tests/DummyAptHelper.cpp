#include <QList>

#include "DummyAptHelper.h"
#include "../dto/packagedto.h"

DummyAptHelper::DummyAptHelper() {}
DummyAptHelper::~DummyAptHelper() {}

QList<PackageDTO> DummyAptHelper::aptList() {
  return this->packageList;
}

void DummyAptHelper::aptUpdate(bool hasSuperuserAccess) {
  PackageDTO package1(QString("Package1"), QString("Package 1 Description"),
                      QString("0.1"), QString(""), QString("10 MB")),
      package3(QString("Package3"), QString("Package 3 Description"),
               QString("0.3"), QString(""), QString("121 MB")),
      package2(QString("Package2"), QString("Package 2 Description"),
               QString("0.2"), QString(""), QString("56 MB")),
      package4(QString("Package4"), QString("Package 4 Description"),
               QString("0.4"), QString(""), QString("524 MB")),
      package5(QString("Package5"), QString("Package 5 Description"),
               QString("0.5"), QString(""), QString("42 MB"));

  QList<PackageDTO> _packageList;

  _packageList << package1 << package2 << package3 << package4 << package5;

  this->packageList = _packageList;
}
