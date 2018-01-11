#ifndef UI_QUITCONTROLLER_H
#define UI_QUITCONTROLLER_H

#include "viewcontroller.h"

class QuitViewController : public ViewController {
  Q_OBJECT

 public:
  QuitViewController();
  virtual ~QuitViewController();

 public slots:
  void doQuit();
};

#endif
