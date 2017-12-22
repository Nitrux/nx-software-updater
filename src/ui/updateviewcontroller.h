#ifndef UI_UPDATEVIEWCONTROLLER_H
#define UI_UPDATEVIEWCONTROLLER_H

#include "viewcontroller.h"
#include "../helpers/apthelper.h"
#include "../listeners/updatelistener.h"

class UpdateViewController : public ViewController, UpdateListener {
  Q_OBJECT

 private:
  AptHelper* aptHelper;

 public:
  UpdateViewController(AptHelper* aptHelper);
  virtual ~UpdateViewController();

 protected:
  virtual void onUpdateComplete();

 public slots:
  void doUpdate();

 signals:
  void updateComplete();
};

#endif
