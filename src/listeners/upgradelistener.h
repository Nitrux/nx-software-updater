#ifndef LISTENERS_UPGRADELISTENER_H
#define LISTENERS_UPGRADELISTENER_H

class UpgradeListener {
 public:
  virtual ~UpgradeListener() {}
  virtual void onUpgradeComplete() = 0;
};

#endif
