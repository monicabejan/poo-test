#include "../include/meniu.h"
#include "../include/hotel.h"
#include <iostream>
#include <string>

hotel *h = hotel::getInstanta();

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

    auto utilizatorGasit = h->identificareUtilizator(idCautat, parolaIntrodusa);
    if (utilizatorGasit!=nullptr) {
        utilizatorLogat = utilizatorGasit;
        std::cout << "\nWelcome, " << utilizatorLogat->getNume() << "\n";
    } else {
        std::cout << "\nID sau parola incorecte\n";
        utilizatorLogat = nullptr;
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
        
        std::cout << "Optiune: ";
        std::cin >> optiune;

        if (optiune == 1) {
            h->afisareCamereLibere();
        } else if (optiune == 2) {
            // hotel.creeazaCamera<cameraDouble>(...)
        }
        else if (optiune == 0){
            std::cout<<"exit";

        }
        else std::cout<<"Invalid";
    }while (optiune != 0) ;

    utilizatorLogat = nullptr;
}

void meniu::afiseazaMeniuClient(){
    int optiune = 0;
    
    do{
        std::cout << "\nMENIU CLIENT\n";
        std::cout << "0. Exit\n";
        std::cout << "1. Afiseaza toate camerele\n";
        std::cout << "2. Rezervare\n";
        
        std::cout << "Optiune: ";
        std::cin >> optiune;

        if (optiune == 1) {
            h->afisareCamereLibere();
        } else if (optiune == 2) {
            // hotel.rezervaCamerainSesiune()
        }
        else if (optiune == 0){
            std::cout<<"exit";

        }
        else std::cout<<"Invalid";
    }while (optiune != 0) ;

    utilizatorLogat = nullptr;
}

void meniu::ruleaza() {
    int optiune = 0;

    do{
         if (utilizatorLogat == nullptr) {
            afiseazaMeniuInitial();
            std::cin>>optiune;

            if (optiune == 1) login();
            else if (optiune == 2) signup();
            else if (optiune == 0) std::cout<<"exit\n";
            else { std::cout<<"\nOptiune invalida";}
       
        } else {
            if (std::dynamic_pointer_cast<angajat>(utilizatorLogat) != nullptr) {
                afiseazaMeniuAngajat();
            } else {
                afiseazaMeniuClient();
            }
        }
    }while (optiune != 0 || utilizatorLogat != nullptr) ;
}