#ifndef REZERVARE_H
#define REZERVARE_H

#include <iostream>

class rezervare{
    static int contorID;
    int idRezervare;
    std::string numeClient;
    int nrNopti;
public:
    rezervare(const std::string & nume, int nopti);
    int getID() {return idRezervare;}
    int getNrNopti() {return nrNopti;}
};

#endif