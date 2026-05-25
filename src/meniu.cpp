#include "../include/meniu.h"
#include "../include/hotel.h"
#include "../include/exceptii.h"
#include <iostream>
#include <string>

hotel *h = hotel::getInstanta();

void curataBuffer() {
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}


void meniu::afiseazaMeniuInitial() const{
    std::cout<<"\nMENIU INTERACTIV\n";
    std::cout<<"\n0. Exit";
    std::cout<<"\n1. Login";
    std::cout<<"\n2. Sign-up";
    std::cout<<"\nOptiune: ";
}


void meniu::login(){
    int idCautat;
    std::string parolaIntrodusa;

    std::cout<<"\nID: ";
    std::cin>>idCautat;
    std::cout<<"\nParola: ";
    std::cin>>parolaIntrodusa;

    try{
        utilizatorLogat = h->identificareUtilizator(idCautat, parolaIntrodusa);
        std::cout<<"\nWelcome, "<<utilizatorLogat->getNume() <<"\n";
    }
    catch(const exceptieAutentificareEsuata& e) {
        std::cout<<"\nEroare: "<<e.what()<<"\n";
        utilizatorLogat=nullptr;    
    }
}



void meniu::signup(){
    std::string nume, prenume, parola, abonament;
    std::cout<<"\nNume: ";
    std::cin>>nume;
    std::cout<<"\nPrenume: ";
    std::cin>>prenume;
    std::cout<<"Parola: ";
    std::cin>>parola;
    std::cout<<"Tip Abonament (Regular/Silver/Gold): ";
    std::cin>>abonament;

    int idNou = h->adaugaClientNou(nume, prenume, parola, abonament);
    std::cout << "ID-ul tau de login este: " << idNou << "\n";
   
    
}



void meniu::afiseazaMeniuAngajat(){
    int optiune = 0;
    
    do{
        std::cout << "\nMENIU ANGAJAT\n";
        std::cout << "0. Exit\n";
        std::cout << "1. Afiseaza toate camerele\n";
        std::cout << "2. Adauga o camera noua\n";
        std::cout << "3. Istoric rezervari\n";
        std::cout << "Optiune: ";

        std::cin >> optiune;

        switch (optiune) {
            case 0:
                std::cout << "\nLogging out\n";
                break;
            case 1:
                h->afisareCamereLibere();
                break;
            case 2:
                std::cout << "\n";
                break;
            case 3:
                h->afisareIstoricRezervari();
                break;
            default:
                std::cout << "Optiune invalida. Incercati din nou.\n";
                break;
        }
    }while (optiune != 0) ;

    utilizatorLogat = nullptr;
}



void meniu::afiseazaMeniuClient(){
    int optiune = 0;
    
    do{
        std::cout << "\nMENIU CLIENT\n";
        std::cout << "0. Exit\n";
        std::cout << "1. Vezi camerele libere\n";
        std::cout << "2. Rezervare\n"; 
        std::cout << "Optiune: ";

        std::cin >> optiune;

       switch (optiune) {
            case 0:
                std::cout << "\nLogging out\n";
                break;
            case 1:
                h->afisareCamereLibere();
                break;
            case 2:
                afisareSubmeniuRezervare(); 
                break;
            default:
                std::cout << "Optiune invalida. Incercati din nou\n";
                break;
        }
    }while (optiune != 0) ;

    utilizatorLogat = nullptr;
}


void meniu::afisareSubmeniuRezervare(){
    int optiune=0;
    int nopti=0;

    std::cout<<"\nREZERVARE NOUA\n";
    std::cout<<"\nNr nopti: ";
    std::cin>>nopti;

    do {
        h->afisareCamereLibere();

        std::cout << "\nREZERVARE CURENTA\n";
        std::cout << "1. Adauga camera la rezervare\n";
        std::cout << "2. Adauga Servicii Optionale\n";
        std::cout << "0. Finalizeaza\n";
        std::cout << "Optiune: ";
        
        switch (optiune) {
            case 0:
                std::cout << "\nAfisare detalii\n";
                break;
            case 1: { 
                int nrCam;
                std::cout << "Camera: ";
                std::cin >> nrCam;

                try {
                    std::string numeComplet = utilizatorLogat->getNume() + " " + utilizatorLogat->getPrenume();
                    h->proceseazaSelectieCamera(nrCam, nopti, numeComplet);
                    
                    std::cout << "\nCamera " << nrCam << " a fost adaugata in rezervare\n";
                } 
                catch (const exceptieCameraInexistenta& e) {
                    std::cout << "\nEroare: " << e.what() << "\n";
                } 
                catch (const exceptieCameraDejaOcupata& e) {
                    std::cout << "\nEroare: " << e.what() << "\n";
                } 
                catch (const std::invalid_argument& e) {
                    std::cout << "\nEroare: " << e.what() << "\n";
                }
                break;
            }
            case 2:
                std::cout << "\n";
                break;
            default:
                std::cout << "\nOptiune invalida\n";
                break;
        }

    } while (optiune != 0);
}


void meniu::ruleaza() {
    int optiune = 0;

    do{
         if (utilizatorLogat == nullptr) {
            afiseazaMeniuInitial();
            std::cin>>optiune;

            switch (optiune) {
                case 0: std::cout << "\nExit\n"; break;
                case 1: login(); break;
                case 2: signup(); break;
                default: std::cout << "Optiune invalida!\n"; break;
            }
        } else {
            if (std::dynamic_pointer_cast<angajat>(utilizatorLogat) != nullptr) {
                afiseazaMeniuAngajat();
            } else {
                afiseazaMeniuClient();
            }
        }
    }while (optiune != 0 || utilizatorLogat != nullptr) ;
}