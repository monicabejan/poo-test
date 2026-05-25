#ifndef HOTEL_H
#define HOTEL_H

#include "../include/camera.h"
#include "../include/persoana.h"
#include "../include/rezervare.h"

#include <iostream>
#include <vector>
#include <memory>

class hotel{
  std::vector<std::shared_ptr<camera>> camere;
  std::vector<rezervare> istoricRezervari;
  std::vector<std::shared_ptr<angajat>> angajati;

  hotel () {}
  hotel(const hotel &) = delete;
  hotel& operator=(const hotel&)=delete; // prevenim copierea (Singleton)

public:

  static hotel* getInstanta();

  void doarAsa();

  void afisareCamereLibere() const;
  
  template <typename T, typename... Args>
    void creeazaCamera(Args&&... args){
        auto cameraNoua=std::make_shared<T>(args...);
        camere.push_back(cameraNoua);
    }

};

#endif
