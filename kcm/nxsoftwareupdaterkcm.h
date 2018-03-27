#ifndef NXSOFTWAREUPDATERKCM_H
#define NXSOFTWAREUPDATERKCM_H

#include <KQuickAddons/ConfigModule>

class NxSoftwareUpdaterKCM : public KQuickAddons::ConfigModule {
  Q_OBJECT
 public:
  explicit NxSoftwareUpdaterKCM(QObject* parent, const QVariantList& args);

  ~NxSoftwareUpdaterKCM();
};

#endif
