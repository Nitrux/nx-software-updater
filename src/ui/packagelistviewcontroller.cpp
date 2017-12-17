#include <QDebug>
#include <QList>

#include "../dto/packagedto.h"
#include "packagelistviewcontroller.h"

PackageListViewController::PackageListViewController() {}
PackageListViewController::~PackageListViewController() {}

void PackageListViewController::updateClicked() {
  qDebug() << ">>>> CPP update clicked....";

  emit packageListChanged();
}
