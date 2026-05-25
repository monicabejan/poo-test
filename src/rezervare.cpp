#include "../include/rezervare.h"

#include <iostream>
#include <string>

int rezervare::contorID=0;

rezervare::rezervare(const std::string& nume, int nopti) : numeClient(nume), nrNopti(nopti) {
    if(nopti<=0) std::cout<<"eroare\n"; //throw exception
    idRezervare= ++contorID;
}