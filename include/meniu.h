#ifndef MENIU_H
#define MENIU_H

#include <vector>
#include "persoana.h"
#include "hotel.h"

class meniu {
private:
    persoana* utilizatorLogat;

    void afiseazaMeniuInitial() const;
    void afiseazaMeniuAngajat();
    void afiseazaMeniuClient();
    
    void login();
    void signup();

public:
    meniu()=default;
    void ruleaza(); 
};

#endif