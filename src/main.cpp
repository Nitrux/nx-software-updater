#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "ui/remindlaterviewcontroller.h"
#include "ui/packagelistviewcontroller.h"
#include "helpers/apthelper.h"

AptHelper* aptHelper = nullptr;

RemindLaterViewController* remindlaterviewcontroller = nullptr;
PackageListViewController* packagelistviewcontroller = nullptr;

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
    packagelistviewcontroller = new PackageListViewController(aptHelper);
  }

  return packagelistviewcontroller;
}

int main(int argc, char* argv[]) {
  const char* uri = "org.nxos.softwareupdater";

  QGuiApplication app(argc, argv);
  QQmlApplicationEngine engine;

  /*    INIT Entities and Helpers   */
  aptHelper = new AptHelper();
  /*    END INIT Entities and Helpers   */

  /*    INIT View Controllers   */
  qmlRegisterSingletonType<RemindLaterViewController>(
      uri, 1, 0, "RemindLaterViewController",
      remindlaterviewcontroller_singleton_provider);

  qmlRegisterSingletonType<PackageListViewController>(
      uri, 1, 0, "PackageListViewController",
      packagelistviewcontroller_singleton_provider);
  /*    END INIT View Controllers   */

  QCoreApplication::addLibraryPath("./");
  QCoreApplication::setOrganizationName("NXOS");
  QCoreApplication::setOrganizationDomain("nxos.org");
  QCoreApplication::setApplicationName("nx-software-updater");

  engine.load(QUrl(QStringLiteral("qrc:/MainComponent.qml")));

  return app.exec();
}
