#include "../include/hotel.h"

#include <iostream>

hotel* hotel::getInstanta() {
  static hotel instantaUnica;
  return &instantaUnica;
}

void hotel::doarAsa() {
  std::cout<<" ";
}

void hotel::afisareCamereLibere() const{
  std::cout<<"\nCAMERE DISPONIBILE:\n";

  bool existaLibere=false;
  for(const auto& cam : camere){
    if(!cam -> esteOcupata()){
      std::cout<<*cam<<"\n";
      existaLibere=true;
    }
  }
  if(!existaLibere)
    std::cout<<"\nNicio camera disponibila\n";
}