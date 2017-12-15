#include <QDebug>
#include <QSignalSpy>
#include <QTest>
#include <QDate>

#include "../entities/reminder.h"

class EntitiesTests : public QObject {
  Q_OBJECT

 private slots:
  void testSetLastNotificationDate() {
    Reminder reminder;

    qDebug() << "testing...";

    reminder.setLastNotificationDate(QDate::currentDate());
    QVERIFY(reminder.getLastNotificationDate() == QDate::currentDate());
  }
};

QTEST_MAIN(EntitiesTests)
#include "entities_tests.moc"
