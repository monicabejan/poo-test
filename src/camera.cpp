#include "../include/camera.h"

#include <iostream>

camera::camera(int nr, int et, double p, bool st) : nrCamera(nr), etaj(et), pret(p), status(st) {}
camera::camera(const camera& other) : nrCamera(other.nrCamera), etaj(other.etaj), pret(other.pret), status(other.status) {}
camera& camera::operator=(const camera& other) {
    if(this!=&other){
        nrCamera=other.nrCamera;
        etaj=other.etaj;
        pret=other.pret;
        status=other.status;
    }
    return *this;
}
std::ostream& operator<<(std::ostream& os, const camera& c) {
    os<<"\nNr: "<<c.nrCamera
      <<"\nEtaj: "<<c.etaj
      <<"\nTip: "<<c.getTip();
    c.afisareDetalii(os);
    return os;
} 

cameraSingle::cameraSingle(int nr, int et, double p):camera(nr, et, p) {}
cameraSingle::cameraSingle(const cameraSingle& other): camera(other) {}
cameraSingle& cameraSingle::operator=(const cameraSingle& other){
    if(this!=&other)
        camera::operator=(other);
    return *this;
}

cameraDouble::cameraDouble(int nr, int et, const std::string& config, double p) : camera(nr, et, p), tipConfiguratie(config) {}
cameraDouble::cameraDouble(const cameraDouble& other) : camera(other), tipConfiguratie(other.tipConfiguratie) {}
cameraDouble& cameraDouble::operator=(const cameraDouble& other){
    if(this!=&other){
        camera::operator=(other);
        tipConfiguratie=other.tipConfiguratie;
    }
    return *this;
}


penthouse::penthouse(int nr, int et, int nrDorm, double p): camera(nr, et, p), nrDormitoare(nrDorm) {}
penthouse::penthouse(const penthouse& other): camera(other), nrDormitoare(other.nrDormitoare) {}
penthouse& penthouse::operator=(const penthouse& other){
    if(this!=&other){
        camera::operator=(other);
        nrDormitoare=other.nrDormitoare;
    }
    return *this;
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