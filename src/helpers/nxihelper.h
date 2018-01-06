
#ifndef HELPERS_NXIHELPER_H
#define HELPERS_NXIHELPER_H

#include <QList>
#include <QObject>
#include <string>
#include <functional>

#include "../dto/packagedto.h"
#include "../listeners/packagelistlistener.h"
#include "shellhelper.h"

using namespace std;

class NxiHelper : public QObject {
  Q_OBJECT

 public:
  NxiHelper(QObject* parent = nullptr);
  virtual ~NxiHelper();

  void nxiList(function<void(int)> lambda);
  void nxiUpdate(function<void(int)> lambda);
  void nxiUpgrade(function<void(int)> lambda);

 public slots:
  void onRunNxiList();
  void onRunNxiUpdate();
  void onRunNxiUpgrade();

 signals:
  void onNxiListComplete(QList<PackageDTO*> packageList);
  void onNxiUpdateComplete();
  void onNxiUpgradeComplete();

 private:
  QList<PackageDTO*> parsePackageListFile(std::string path);
  ShellHelper* shellHelper;
  string storageBasePath;
};

#endif
