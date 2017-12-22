#ifndef LISTENERS_UPDATELISTENER_H
#define LISTENERS_UPDATELISTENER_H

class UpdateListener {
 public:
  virtual ~UpdateListener() {}
  virtual void onUpdateComplete() = 0;
};

#endif
