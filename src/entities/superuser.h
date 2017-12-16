#ifndef ENTITIES_SUPERUSER_H
#define ENTITIES_SUPERUSER_H

class Superuser {
 public:
  Superuser();
  virtual ~Superuser();

  bool checkPermission();
};

#endif
