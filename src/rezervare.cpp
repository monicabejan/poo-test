#include "../include/rezervare.h"
#include <stdexcept>
#include <iostream>
#include <string>

int rezervare::contorID=0;

rezervare::rezervare(const std::string& nume, int nopti) : numeClient(nume), nrNopti(nopti) {
    if(nopti<=0) {
        throw std::invalid_argument("Nr de nopti nu poate fi negativ");
    }
    idRezervare= ++contorID;
}

rezervare::rezervare(const rezervare& other) :  numeClient(other.numeClient), nrNopti(other.nrNopti), costTotal(other.costTotal), serviciiAlese(other.serviciiAlese), camereAlese(other.camereAlese) 
    { idRezervare=++contorID;}

rezervare & rezervare::operator=(const rezervare&  other){
    if(this!=&other){
        idRezervare=other.idRezervare;
        numeClient=other.numeClient;
        nrNopti=other.nrNopti;
        costTotal=other.costTotal;
        serviciiAlese=other.serviciiAlese;
        camereAlese=other.camereAlese;
    }
    return *this;
}

std::istream& operator>>(std::istream& is, rezervare& rez) {
     is >> rez.numeClient >> rez.nrNopti; 
     return is;
     }

std::ostream& operator<<(std::ostream& os, const rezervare& rez) {
    os<<"\nRezervare #"<<rez.idRezervare
      <<"\nClient: "<<rez.numeClient
      <<"\nDurata: "<<rez.nrNopti<<" nopti\n";

      os<<"\nCamere: ";
      for(const auto& cam : rez.camereAlese){
        os<<"\n"<<cam->getNrCamera()<<" "<<cam->getTip();
      }

    if(!rez.serviciiAlese.empty()){
        os<<"Servicii suplimentare : ";
        for(const auto& s: rez.serviciiAlese){
            os<<"\n";
            s->afisareDetaliiServiciu(os);
            os<<s->getPret()<< " RON";
        }
    }
    os<<"\nCost total: "<<rez.costTotal<<" RON";
    return os;
}

bool rezervare::operator==(const rezervare& other) const { 
    return idRezervare == other.idRezervare; 
}