#ifndef MENIU_H
#define MENIU_H

#include <vector>
#include "persoana.h"
#include "hotel.h"

class meniu {
private:
    hotel& m_hotel;
    persoana* utilizatorLogat;

    void afiseazaMeniuInitial() const;
    void afiseazaMeniuAngajat();
    void afiseazaMeniuClient();
    
    void login();
    void signup();

public:
    explicit meniu(hotel& instantaHotel): m_hotel(instantaHotel), utilizatorLogat(nullptr) {}
    void ruleaza(); 
};

#endif