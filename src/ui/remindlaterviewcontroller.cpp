#include <iostream>
#include <QDebug>
#include "remindlaterviewcontroller.h"

using namespace std;

RemindLaterViewController::RemindLaterViewController() {}
RemindLaterViewController::~RemindLaterViewController() {}

void RemindLaterViewController::clicked() {
  qDebug() << "Remind Later Clicked";
  cout << "cout : Remind Later Clicked\n";
}
