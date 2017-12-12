#ifndef UI_REMINDLATERCONTROLLER_H
#define UI_REMINDLATERCONTROLLER_H

#include "../interactors/interactor.h"

class RemindLaterViewController : public Interactor {
  Q_OBJECT

 public:
  RemindLaterViewController();
  virtual ~RemindLaterViewController();

  Q_INVOKABLE void clicked();
};

#endif
