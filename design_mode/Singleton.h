#ifndef SIGNLETON_H
#define SIGNLETON_H

template <typename T>
class Singleton {
public:
  static Singleton* getInstancePtr();
  static Singleton getInstance();
private:
  Singleton();
  static Singleton *instance;
};