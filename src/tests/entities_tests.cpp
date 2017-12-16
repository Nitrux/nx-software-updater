#include <QDebug>
#include <QSignalSpy>
#include <QTest>
#include <QDate>

#include "../entities/reminder.h"

class EntitiesTests : public QObject {
  Q_OBJECT

 private slots:
  void testGetSetLastNotificationDate() {
    Reminder reminder;

    reminder.setLastNotificationDate(QDate::currentDate());
    QVERIFY(reminder.getLastNotificationDate() == QDate::currentDate());

    reminder.setLastNotificationDate(QDate::currentDate().addDays(1));
    QVERIFY(reminder.getLastNotificationDate() ==
            QDate::currentDate().addDays(1));
  }
};

QTEST_MAIN(EntitiesTests)
#include "entities_tests.moc"
