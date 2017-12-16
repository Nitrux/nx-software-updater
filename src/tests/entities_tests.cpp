#include <QDebug>
#include <QSignalSpy>
#include <QTest>
#include <QDate>
#include <sys/types.h>
#include <unistd.h>

#include "DummyAptHelper.h"

#include "../entities/superuser.h"
#include "../entities/reminder.h"
#include "../entities/packages.h"

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

    QVERIFY(shouldShowNotification == false);

    reminder.setLastNotificationDate(lastNotificationDate2);
    shouldShowNotification = reminder.shouldShowNotification();

    QVERIFY(shouldShowNotification == true);
  }

  void testFetchListOfPackages() {
    DummyAptHelper aptHelper;
    Packages packages(&aptHelper);

    //    qInfo() << "AptHelper Packages before Update : "
    //            << aptHelper.aptList().size();
    QVERIFY(packages.fetchListOfPackages().size() == 0);

    aptHelper.aptUpdate(false);

    //    qInfo() << "AptHelper Packages after Update : "
    //            << aptHelper.aptList().size();
    QVERIFY(packages.fetchListOfPackages().size() == 5);
  }

  void testSuperuserAccess() {
    Superuser su;

    if (geteuid() > 0) {
      QVERIFY(su.checkPermission() == true);
    } else {
      QVERIFY(su.checkPermission() == false);
    }
  }
};

QTEST_MAIN(EntitiesTests)
#include "entities_tests.moc"
