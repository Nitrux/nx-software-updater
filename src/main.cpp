#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "ui/remindlaterviewcontroller.h"

RemindLaterViewController* remindlaterviewcontroller = nullptr;

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

int main(int argc, char* argv[]) {
  const char* uri = "org.nxos.softwareupdater";

  QGuiApplication app(argc, argv);
  QQmlApplicationEngine engine;

  qmlRegisterSingletonType<RemindLaterViewController>(
      uri, 1, 0, "RemindLaterViewController",
      remindlaterviewcontroller_singleton_provider);

  //  qmlRegisterType<RemindLaterViewController>(uri, 1, 0,
  //                                             "RemindLaterViewController");

  QCoreApplication::addLibraryPath("./");
  QCoreApplication::setOrganizationName("NXOS");
  QCoreApplication::setOrganizationDomain("nxos.org");
  QCoreApplication::setApplicationName("nx-software-updater");

  engine.load(QUrl(QStringLiteral("qrc:/MainComponent.qml")));

  return app.exec();
}
