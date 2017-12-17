#ifndef UI_VIEWCONTROLLER_H
#define UI_VIEWCONTROLLER_H

#include <QObject>

class ViewController : public QObject {
  Q_OBJECT

 public:
  ViewController(QObject* parent = nullptr);
  virtual ~ViewController();
};

#endif
