#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char* argv[]) {
  const char* uri = "org.nx.softwareupdater";

  QGuiApplication app(argc, argv);
  QQmlApplicationEngine engine;

  QCoreApplication::addLibraryPath("./");
  QCoreApplication::setOrganizationName("NXOS");
  QCoreApplication::setOrganizationDomain("nxos.org");
  QCoreApplication::setApplicationName("nx-software-updater");

  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

  return app.exec();
}
