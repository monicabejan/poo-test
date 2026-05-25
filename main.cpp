#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include "../include/hotel.h"
#include "../include/persoana.h"
#include "../include/camera.h"
#include "../include/rezervare.h"
#include "../include/serviciu.h"
#include "../include/exceptii.h"
#include "../include/meniu.h"

int main() {

    std::ifstream fisierInput("tastatura.txt");
    std::cin.rdbuf(fisierInput.rdbuf());

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

    client cli("nume", "prenume", "silver");
    cli.upgradeAbonament("golden");
    std::cout<<cli.getNume();
    std::cout<<cli.getPrenume();
    std::cout<<cli.getTipAbonament();

    angajat ang("nume", "prenume", 1000);
    std::cout<<ang.getSalariu();
    
    meniu Meniu;
    Meniu.ruleaza();

    return 0;
}
