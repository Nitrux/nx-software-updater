#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>

#include "ui/remindlaterviewcontroller.h"
#include "ui/packagelistviewcontroller.h"
#include "ui/updateviewcontroller.h"
#include "ui/upgradeviewcontroller.h"
#include "ui/quitviewcontroller.h"
#include "entities/packagemanager.h"
#include "entities/apt.h"
#include "entities/nxi.h"

PackageManager* packageManager = nullptr;

RemindLaterViewController* remindlaterviewcontroller = nullptr;
PackageListViewController* packagelistviewcontroller = nullptr;
UpdateViewController* updateviewcontroller = nullptr;
UpgradeViewController* upgradeviewcontroller = nullptr;
QuitViewController* quitviewcontroller = nullptr;

static QObject* remindlaterviewcontroller_singleton_provider(
    QQmlEngine* engine,
    QJSEngine* scriptEngine) {
  Q_UNUSED(engine)
  Q_UNUSED(scriptEngine)

  if (remindlaterviewcontroller == nullptr) {
    remindlaterviewcontroller = new RemindLaterViewController();
  }

  return remindlaterviewcontroller;
}

static QObject* packagelistviewcontroller_singleton_provider(
    QQmlEngine* engine,
    QJSEngine* scriptEngine) {
  Q_UNUSED(engine)
  Q_UNUSED(scriptEngine)

  if (packagelistviewcontroller == nullptr) {
    packagelistviewcontroller = new PackageListViewController(packageManager);
  }

  return packagelistviewcontroller;
}

static QObject* updateviewcontroller_singleton_provider(
    QQmlEngine* engine,
    QJSEngine* scriptEngine) {
  Q_UNUSED(engine)
  Q_UNUSED(scriptEngine)

  if (updateviewcontroller == nullptr) {
    updateviewcontroller = new UpdateViewController(packageManager);
  }

  return updateviewcontroller;
}

static QObject* upgradeviewcontroller_singleton_provider(
    QQmlEngine* engine,
    QJSEngine* scriptEngine) {
  Q_UNUSED(engine)
  Q_UNUSED(scriptEngine)

  if (upgradeviewcontroller == nullptr) {
    upgradeviewcontroller = new UpgradeViewController(packageManager);
  }

  return upgradeviewcontroller;
}

static QObject* quitviewcontroller_singleton_provider(QQmlEngine* engine,
                                                      QJSEngine* scriptEngine) {
  Q_UNUSED(engine)
  Q_UNUSED(scriptEngine)

  if (quitviewcontroller == nullptr) {
    quitviewcontroller = new QuitViewController();
  }

  return quitviewcontroller;
}

int main(int argc, char* argv[]) {
  const char* uri = "org.nxos.softwareupdater";

  QGuiApplication app(argc, argv);
  QQmlApplicationEngine engine;

  qDebug() << ">>>> PackageManagerType : "
           << PackageManager::getPackageManagerType();

  /*    INIT Entities and Helpers   */
  switch (PackageManager::getPackageManagerType()) {
    case PackageManagerType::APT:
      qDebug() << "PackageManager : APT";
      packageManager = new Apt();
      break;

    case PackageManagerType::NXI:
      qDebug() << "PackageManager : NXI";
      packageManager = new Nxi();
      break;
  }
  /*    END INIT Entities and Helpers   */

  /*    INIT View Controllers   */
  qmlRegisterSingletonType<RemindLaterViewController>(
      uri, 1, 0, "RemindLaterViewController",
      remindlaterviewcontroller_singleton_provider);

  qmlRegisterSingletonType<PackageListViewController>(
      uri, 1, 0, "PackageListViewController",
      packagelistviewcontroller_singleton_provider);

  qmlRegisterSingletonType<UpdateViewController>(
      uri, 1, 0, "UpdateViewController",
      updateviewcontroller_singleton_provider);

  qmlRegisterSingletonType<UpgradeViewController>(
      uri, 1, 0, "UpgradeViewController",
      upgradeviewcontroller_singleton_provider);

  qmlRegisterSingletonType<QuitViewController>(
      uri, 1, 0, "QuitViewController", quitviewcontroller_singleton_provider);
  /*    END INIT View Controllers   */

  QCoreApplication::addLibraryPath("./");
  QCoreApplication::setOrganizationName("NXOS");
  QCoreApplication::setOrganizationDomain("nxos.org");
  QCoreApplication::setApplicationName("nx-software-updater");

  engine.load(QUrl(QStringLiteral("qrc:/MainComponent.qml")));

  return app.exec();
}
