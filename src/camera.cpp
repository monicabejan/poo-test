#include "../include/camera.h"

#include <iostream>

std::ostream& operator<<(std::ostream& os, const camera& c) {
    os<<"\nNr: "<<c.nrCamera
      <<"\nEtaj: "<<c.etaj
      <<"\nTip: "<<c.getTip();
    c.afisareDetalii(os);
    return os;
} 

void cameraSingle::afisareDetalii(std::ostream& os) const {
    os<<" ";
}

void cameraDouble::afisareDetalii (std::ostream& os) const{
    os<<"\nConfiguratie: "<<tipConfiguratie;
}

void penthouse::afisareDetalii(std::ostream& os) const {
    os<<"\n"<<nrDormitoare<<" dormitoare";
}