#include <QDebug>

#include "quitviewcontroller.h"
#include "../interactors/quitinteractor.h"

QuitViewController::QuitViewController() {}
QuitViewController::~QuitViewController() {}

void QuitViewController::doQuit() {
  QuitInteractor* quitInteractor = new QuitInteractor();

  quitInteractor->execute();
}
