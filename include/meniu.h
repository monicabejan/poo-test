#ifndef MENIU_H
#define MENIU_H

#include <vector>
#include "persoana.h"
#include "hotel.h"

class meniu {
private:
    std::shared_ptr<persoana> utilizatorLogat=nullptr;

    void afiseazaMeniuInitial() const;
    void afiseazaMeniuAngajat();
    void afiseazaMeniuClient();
    void afisareSubmeniuRezervare();
    
    void login();
    void signup();

public:
    meniu()=default;
    void ruleaza(); 
};

#endif