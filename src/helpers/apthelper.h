
#ifndef HELPERS_APTHELPER_H
#define HELPERS_APTHELPER_H

#include <QList>
#include <QString>

class AptHelper {
 public:
  AptHelper();
  virtual ~AptHelper();

  QList<QString> aptList();
  void aptUpdate(bool hasSuperuserAccess);
  void aptUpgrade(bool hasSuperuserAccess);
};

#endif
