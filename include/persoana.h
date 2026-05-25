#ifndef PERSOANA_H
#define PERSOANA_H

#include <iostream>


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
};




#endif