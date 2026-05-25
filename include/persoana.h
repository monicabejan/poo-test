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
    std::string parola;

public:
    int getID() const { return id; }
    persoana(const std::string& nume, const std::string& prenume, const std::string& par = "1234") : nume(nume), prenume(prenume), parola(par) { this->id=++contorID;}
    void doSomething () ;
    virtual ~persoana()=default;

    const std::string& getNume() const {return nume;}
    const std::string& getPrenume() const {return prenume;}
    const std::string& getParola() const { return parola; }
};



class client: public persoana {
    std::string tipAbonament;
public:
    ~client() override = default;
    client(const std::string& nume, const std::string& prenume, const std::string& abonament, const std::string& par = "1234"): persoana(nume, prenume, par), tipAbonament(abonament) {}

    const std::string& getTipAbonament() const {return tipAbonament;}
    void upgradeAbonament(const std::string& abNou) { tipAbonament = abNou; }

};


class angajat: public persoana{
    double salariu;
public:
    ~angajat() override = default;
    angajat(const std::string& nume, const std::string& prenume, double sal) : persoana(nume, prenume), salariu(sal) {}

    double getSalariu() const {return salariu;}
};

#endif