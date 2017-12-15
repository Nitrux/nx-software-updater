#include <QSettings>

#include "reminder.h"

Reminder::Reminder() {}
Reminder::~Reminder() {}

bool Reminder::shouldShowNotification(QDate date) {}

void Reminder::createNotification() {}

QDate Reminder::getLastNotificationDate() {
  QSettings settings;

  QDate date = settings.value("reminder/lastNotificationDate").toDate();

  return date;
}

void Reminder::setLastNotificationDate(QDate date) {
  QSettings settings;

  settings.setValue("reminder/lastNotificationDate", date);
}
