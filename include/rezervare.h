#ifndef REZERVARE_H
#define REZERVARE_H

#include <iostream>
#include <memory>
#include <vector>
#include "../include/serviciu.h"
#include "../include/camera.h"

class rezervare{
    static int contorID;
    int idRezervare;
    std::string numeClient;
    int nrNopti;
    double costTotal;

    std::vector<std::shared_ptr<serviciu>> serviciiAlese;
    std::vector<std::shared_ptr<camera>> camereAlese;

public:
    rezervare(const std::string & nume, int nopti);
    int getID() {return idRezervare;}
    int getNrNopti() {return nrNopti;}

    void adaugaCamera(std::shared_ptr<camera> cam) { camereAlese.push_back(cam); }

    void adaugaServiciu(std::shared_ptr<serviciu> serv){ serviciiAlese.push_back(serv);}
    void setCostTotal(double cost) { costTotal=cost;}
    double getCostTotal() const {return costTotal;}

    const std::vector<std::shared_ptr<camera>>& getCamere() const { return camereAlese; }
    const std::vector<std::shared_ptr<serviciu>>& getServicii() const{ return serviciiAlese;}

    friend std::ostream& operator<<(std::ostream& os, const rezervare& rez);
};

#endif