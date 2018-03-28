#ifndef SOFTWAREUPDATERPLUGIN_H
#define SOFTWAREUPDATERPLUGIN_H

#include <QQmlEngine>
#include <QQmlExtensionPlugin>

class SoftwareUpdaterPlugin : public QQmlExtensionPlugin {
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

 public:
  virtual void registerTypes(const char* uri);
};

#endif
