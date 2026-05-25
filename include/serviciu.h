#ifndef SERVICIU_H
#define SERVICIU_H

#include <iostream>
#include <string>

class serviciu {
protected:
    std::string denumire;
    double pret;
public:
    serviciu(const std::string& den, double pret) : denumire(den), pret(pret) {}
    const std::string& getDenumire() const {return denumire;}
    double getPret() const {return pret;}

};

#endif