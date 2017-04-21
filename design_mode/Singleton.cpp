#include "Singleton.h"

template <typename T>
Singleton* Singleton<T>::instance = NULL;

template <typename T>
Singleton* Singleton<T>::getInstancePtr() {
  if (instance == NULL) instance = new Singleton();
  return instance;
}

template <typename T>
Singleton Singleton<T>::getInstance() {
  return *getInstancePtr();
}

template <typename T>
Singleton<T>::Singleton() {}