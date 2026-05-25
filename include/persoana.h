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
    persoana(int id, const std::string& nume, const std::string& prenume) : id(id), nume(nume), prenume(prenume) {}; 
    void doSomething () ;
};



#endif