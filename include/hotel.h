#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>

class hotel{
  hotel () {}
  hotel(const hotel &) = delete;
  hotel& operator=(const hotel&)=delete; // prevenim copierea (Singleton)
public:
  static hotel* getInstanta();

  void doarAsa();
    

};

#endif
