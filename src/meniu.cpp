#include "../include/meniu.h"
#include "../include/hotel.h"
#include "../include/exceptii.h"
#include <iostream>
#include <string>

hotel *h = hotel::getInstanta();

// void curataBuffer() {
//     std::cin.clear();
//     std::cin.ignore(10000, '\n');
// }


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
        std::cout <<"4. Vezi total incasari\n";
        std::cout << "Optiune: ";

        std::cin >> optiune;

        switch (optiune) {
            case 0:
                std::cout << "\nLogging out\n";
                break;
            case 1:
                h->afisareToateCamerele();
                break;
            case 2:{
                int tipCam, nr, etaj;
                double pret;
                std::cout<<"\nAdaugare camera noua";
                std::cout<<"1. Single\n2. Double\n3. Penthouse\nTip: ";
                std::cin>>tipCam;
                std::cout<<"\nNumar camera: ";
                std::cin>>nr;
                std::cout<<"\nEtaj: ";
                std::cin>>etaj;
                std::cout<<"\nPret per noapte: ";
                std::cin>>pret;

                try{
                    if(tipCam==1){
                    h->creeazaCamera<cameraSingle>(nr, etaj, pret);
                }else if(tipCam==2){
                    std::string config;
                    std::cout<<"\nConfiguratie (Twin/Matrimonial): ";
                    std::cin>>config;
                    h->creeazaCamera<cameraDouble>(nr, etaj, config, pret);
            
                } else if(tipCam==3){
                    int dorm;
                    std::cout<<"\nNumar dormitoare: ";
                    std::cin>>dorm;
                    h->creeazaCamera<penthouse>(nr, etaj, dorm, pret);
                }else{
                    std::cout<<"\nInvalid\n";
                    break;
                }
                std::cout<<"\nCamera "<<nr<<" a fost creata\n";
                }
                catch( const std::invalid_argument& e){
                    std::cout<<"\nEroare: "<<e.what()<<"\n";
                }

                break;
            }
                
            case 3:
                h->afisareIstoricRezervari();
                break;
            case 4:
                h->afisareTotalIncasari();
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

    std::vector<int> camereTemporare;
    std::vector<std::shared_ptr<serviciu>> serviciiTemporare;

    std::cout<<"\nREZERVARE NOUA\n";
    std::cout<<"\nNr nopti: ";
    std::cin>>nopti;

    do {

        std::cout<<"\nCamere selectate pana acum: ";
        if(camereTemporare.empty()) std::cout<<"Niciuna";
        else for(int c: camereTemporare) std::cout<<"["<<c<<"] ";

        std::cout << "\nREZERVARE CURENTA\n";
        std::cout << "0. Finalizeaza\n";
        std::cout << "1. Adauga camera la rezervare\n";
        std::cout << "2. Adauga Servicii Optionale\n";
        std::cout << "Optiune: ";
        std::cin>>optiune;
        
        switch (optiune) {
            case 0:{
                try{
                    std::string numeComplet = utilizatorLogat->getNume() + " " + utilizatorLogat->getPrenume();
                    std::string abonament = "Regular";
                    auto cl = std::dynamic_pointer_cast<client>(utilizatorLogat);
                    if (cl != nullptr) {
                        abonament = cl->getTipAbonament();
                    }
                    h->proceseazaSelectieCamere(nopti, numeComplet, abonament, camereTemporare, serviciiTemporare);
                    std::cout << "\nRezervare finalizata\n";
                }
                catch( const std::exception& e){
                    std::cout<<"\nEroare: "<<e.what()<<"\n";
                    optiune=-1;
                }
                break;
            }
            case 1: { 
                h->afisareCamereLibere();
                int nrCam;
                std::cout << "Camera: ";
                std::cin >> nrCam;

                bool dejaAdaugata = false;
                for(int c : camereTemporare) {
                    if(c == nrCam) dejaAdaugata = true;
                }
                if(dejaAdaugata) {
                    std::cout<<"\nCamera deja selectata";
                } else {
                    camereTemporare.push_back(nrCam);
                }
                break;
            }
            case 2:{
                int optServ;
                std::cout<<"\nSERVICII\n";
                std::cout<<"0. Inapoi\n";
                std::cout<<"1. Mic dejun\n";
                std::cout<<"2. All inclusive\n";
                std::cout<<"3. Masaj\n";
                std::cout<<"Optiune: \n";
                std::cin>>optServ;

                if (optServ == 1) {
                    serviciiTemporare.push_back(std::make_shared<serviciuMasa>("Mic Dejun", 50.0, "mic dejun"));
                    std::cout << "\nMic dejun adaugat\n";
                } else if (optServ == 2) {
                    serviciiTemporare.push_back(std::make_shared<serviciuMasa>("All Inclusive", 180.0, "all inclusive"));
                    std::cout << "\nPachet All Inclusive adaugat\n";
                } else if (optServ == 3) {
                    serviciiTemporare.push_back(std::make_shared<serviciuSpa>("Masaj", 120.0, 60));
                    std::cout << "\nSPA adaugat\n";
                }
                break;
            }
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