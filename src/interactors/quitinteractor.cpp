#include <QCoreApplication>
#include <kauth.h>

#include "quitinteractor.h"
#include "../actions/actionids.h"

using namespace KAuth;

QuitInteractor::QuitInteractor() {}
QuitInteractor::~QuitInteractor() {}

void QuitInteractor::execute() {
  //  Action(ActionIds::ACTION_RUN_COMMAND).stop();
  QCoreApplication::quit();
}
