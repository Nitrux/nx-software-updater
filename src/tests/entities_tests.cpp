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

  void testShouldShowNotification() {
    Reminder reminder;
    bool shouldShowNotification;
    QDate lastNotificationDate1(QDate::currentDate()),
        lastNotificationDate2(2012, 12, 12);

    reminder.setLastNotificationDate(lastNotificationDate1);
    shouldShowNotification = reminder.shouldShowNotification();

    qInfo() << "shouldShowNotification1: " << shouldShowNotification;

    QVERIFY(shouldShowNotification == false);

    reminder.setLastNotificationDate(lastNotificationDate2);
    shouldShowNotification = reminder.shouldShowNotification();

    qInfo() << "shouldShowNotification2: " << shouldShowNotification;

    QVERIFY(shouldShowNotification == true);
  }
};

QTEST_MAIN(EntitiesTests)
#include "entities_tests.moc"
