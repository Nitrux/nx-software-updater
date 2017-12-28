#include <QDebug>

#include "packagelistinteractor.h"
#include "../listeners/packagelistlistener.h"
#include "../helpers/apthelper.h"

PackageListInteractor::PackageListInteractor(AptHelper* aptHelper,
                                             PackageListListener* listener) {
  this->aptHelper = aptHelper;
  this->listener = listener;

  connect(this, SIGNAL(runAptList()), this->aptHelper, SLOT(onRunAptList()));
  connect(this->aptHelper, SIGNAL(onAptListComplete(QList<PackageDTO*>)), this,
          SLOT(onAptListComplete(QList<PackageDTO*>)));
}
PackageListInteractor::~PackageListInteractor() {}

void PackageListInteractor::execute() {
  //  packageList = this->aptHelper->aptList();
  //  listener->onPackageListReady(&packageList);

  emit runAptList();
}

void PackageListInteractor::onAptListComplete(QList<PackageDTO*> packageList) {
  qDebug() << "SLOT onAptListComplete called : " << packageList.size();

  this->listener->onPackageListReady(&packageList);
}
