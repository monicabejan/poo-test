#include "../include/hotel.h"

#include <iostream>

hotel* hotel::getInstanta() {
  static hotel instantaUnica;
  return &instantaUnica;
}

void hotel::doarAsa() {
  cout<<" ";
}
