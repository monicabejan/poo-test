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

std::ostream& operator<<(std::ostream& os, const rezervare& rez) {
    os<<"\nRezervare #"<<rez.idRezervare
      <<"\nClient: "<<rez.numeClient
      <<"\nDurata: "<<rez.nrNopti<<" nopti\n";
    return os;
}