#ifndef UI_UPDATEVIEWCONTROLLER_H
#define UI_UPDATEVIEWCONTROLLER_H

#include "viewcontroller.h"
#include "../listeners/updatelistener.h"
#include "../entities/packagemanager.h"

class UpdateViewController : public ViewController, UpdateListener {
  Q_OBJECT

 private:
  PackageManager* packageManager;

 public:
  UpdateViewController(PackageManager* packageManager);
  virtual ~UpdateViewController();

 protected:
  virtual void onUpdateComplete();

 public slots:
  void doUpdate();

 signals:
  void updateComplete();
};

#endif
