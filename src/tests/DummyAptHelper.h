#include <QList>

#include "../helpers/apthelper.h"
#include "../dto/packagedto.h"

class DummyAptHelper : public AptHelper {
 private:
  QList<PackageDTO> packageList;

 public:
  DummyAptHelper();
  ~DummyAptHelper();

  QList<PackageDTO> aptList();
  void aptUpdate(bool hasSuperuserAccess);
  void aptUpgrade(bool hasSuperuserAccess);
};
