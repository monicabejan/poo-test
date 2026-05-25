#include <iostream>
#include "../include/hotel.h"
#include "../include/persoana.h"
#include "../include/camera.h"
#include "../include/rezervare.h"
#include "../include/serviciu.h"
#include "../include/exceptii.h"

int main() {
    hotel *h = hotel::getInstanta();
    h->doarAsa();

    persoana p("ana","maria");
    int i=p.getID();
    std::cout<<i;

    rezervare rez("ana",2);
    std::cout<<rez.getID();
    std::cout<<rez.getNrNopti();

    serviciu s("laundry", 20);
    std::cout<<s.getDenumire();
    std::cout<<s.getPret();

    cameraSingle cs(1,1,1);
    std::cout<<cs.getTip();
    std::cout<<cs.esteOcupata();

    cameraDouble cd (1,1,"twin", 5);
    std::cout<<cd.getTip();
    std::cout<<cd.esteOcupata();
    return 0;
}
