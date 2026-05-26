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
    virtual ~serviciu() =default;

    const std::string& getDenumire() const {return denumire;}
    virtual double getPret() const {return pret;}

    virtual void afisareDetaliiServiciu(std::ostream& os) const =0;

};


class serviciuMasa : public serviciu{
    std::string tipMasa;
public:
    serviciuMasa(const std::string& den, double pret, const std::string& tip) : serviciu(den, pret), tipMasa(tip) {}

    void afisareDetaliiServiciu(std::ostream& os) const override {
        os<<denumire<< " ("<<tipMasa<<")";
    }
};


class serviciuSpa: public serviciu{
    int durataMinute;
public:
    serviciuSpa(const std::string& den, double pret, int durata) : serviciu(den, pret), durataMinute(durata) {}

    void afisareDetaliiServiciu(std::ostream& os) const override{
        os<<denumire<<" (Durata: "<<durataMinute<<" min)";
    }
};




#endif