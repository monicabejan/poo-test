#include <iostream>
#include <vector>
#include <memory>
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
    std::cout<<cd.getConfiguratie();

    penthouse ph(2,2,100,500);
    std::cout<<ph.getTip();
    std::cout<<ph.esteOcupata();
    std::cout<<ph.getDormitoare();

    h->creeazaCamera<cameraSingle>(2,2, 200);
    h->creeazaCamera<cameraDouble>(2,2,"matrimonial", 200);
    h->afisareCamereLibere();

    persoana* utilizatorLogat = nullptr;
    int optiune = 0;

    do {
        std::cout<<"\nMENIU INTERACTIV\n";
        std::cout<<"\n0. Exit";
        std::cout<<"\n1. Login";
        std::cout<<"\n2. Sign-up";
        std::cout<<"\nOptiune: ";
        std::cin>>optiune;

        if(optiune==1){std::cout<<"Meniu login";}
        else if(optiune==2) {std::cout<<"Meniu sign up";}
        else if(optiune==0) {std::cout<<"Exit;"}
        else std::cout<<"\nOptiune invalida\n";
    } while (utilizatorLogat == nullptr && optiune != 0);
    

    return 0;
}
