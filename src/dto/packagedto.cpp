#include <QString>
#include <QDebug>

#include "packagedto.h"

PackageDTO::PackageDTO(QString packageName,
                       QString description,
                       QString version,
                       QString iconUrl,
                       QString size) {
  this->packageName = packageName;
  this->description = description;
  this->version = version;
  this->iconUrl = iconUrl;
  this->size = size;
}

/* Start GETTERS */
QString PackageDTO::getPackageName() {
  return this->packageName;
}
QString PackageDTO::getDescription() {
  return this->description;
}
QString PackageDTO::getVersion() {
  return this->version;
}
QString PackageDTO::getIconUrl() {
  return this->iconUrl;
}
QString PackageDTO::getSize() {
  return this->size;
}
/* End GETTERS */
