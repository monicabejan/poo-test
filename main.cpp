#include <iostream>
#include "../include/hotel.h"
#include "../include/persoana.h"
#include "../include/camera.h"
#include "../include/rezervare.h"
#include "../include/serviciu.h"

int main() {
    hotel *h = hotel::getInstanta();
    h->doarAsa();

    persoana p("ana","maria");
    int i=p.getID();
    std::cout<<i;

    camera c(1,1,1);
    std::cout<<c.esteOcupata();

    rezervare rez("ana",2);
    std::cout<<rez.getID();
    std::cout<<rez.getNrNopti();

    serviciu s("laundry", 20);
    std::cout<<s.getDenumire();
    std::cout<<s.getPret();
    return 0;
}
