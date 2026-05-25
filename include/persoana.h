#ifndef PERSOANA_H
#define PERSOANA_H

#include <iostream>
#include <string>


class persoana {
    static int contorID;
protected:
    int id;
    std::string nume;
    std::string prenume;

public:
    int getID() const { return id; }
    persoana(const std::string& nume, const std::string& prenume) : nume(nume), prenume(prenume){ this->id=contorID++;}
    void doSomething () ;
    virtual ~persoana()=default;

    std::string getNume() const {return nume;}
    std::string getPrenume() const {return prenume;}
};



class client: public persoana {
    std::string tipAbonament;
public:
    ~client() override = default;
    client(const std::string& nume, const std::string& prenume, const std::string& abonament): persoana(nume, prenume), tipAbonament(abonament) {}

    std::string getTipAbonament() const {return tipAbonament;}

};


class angajat: public persoana{
    double salariu;
public:
    ~angajat() override = default;
    angajat(const std::string& nume, const std::string& prenume, double sal) : persoana(nume, prenume), salariu(sal) {}

    double getSalariu() const {return salariu;}
};

#endif