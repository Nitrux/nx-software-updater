#ifndef UI_REMINDLATERCONTROLLER_H
#define UI_REMINDLATERCONTROLLER_H

#include <QObject>

class RemindLaterViewController : public QObject {
  Q_OBJECT

 public:
  RemindLaterViewController(QObject* parent = nullptr);
  virtual ~RemindLaterViewController();

  Q_INVOKABLE void clicked();
};

#endif
