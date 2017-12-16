#ifndef DTO_PACKAGEDTO_H
#define DTO_PACKAGEDTO_H

#include <QString>

class PackageDTO {
 private:
  QString packageName, description, version, iconUrl, size;

 public:
  PackageDTO(QString packageName,
             QString description,
             QString version,
             QString iconUrl,
             QString size);

  /* GETTERS */
  QString getPackageName();
  QString getDescription();
  QString getVersion();
  QString getIconUrl();
  QString getSize();

  /* SETTERS */
  void setPackageName(QString packageName);
  void setDescription(QString description);
  void setVersion(QString version);
  void setIconUrl(QString iconUrl);
  void setSize(QString size);
};

#endif
