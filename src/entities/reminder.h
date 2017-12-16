#ifndef ENTITIES_REMINDER_H
#define ENTITIES_REMINDER_H

#include <QDate>

class Reminder {
 public:
  Reminder();
  virtual ~Reminder();

  bool shouldShowNotification();
  void createNotification();
  QDate getLastNotificationDate();
  void setLastNotificationDate(QDate date);
};

#endif
