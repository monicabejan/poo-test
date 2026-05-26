#include "../include/hotel.h"
#include "../include/exceptii.h"

#include <iostream>

hotel::hotel() {
  auto angajatImplicit = std::make_shared<angajat>("Popa", "Andrei", 4000.0);
  utilizatori.push_back(angajatImplicit);
}

hotel* hotel::getInstanta() {
  static hotel instantaUnica;
  return &instantaUnica;
}

void hotel::doarAsa() {
  std::cout<<" ";
}

void hotel::afisareToateCamerele() const{
  std::cout<<"\nTOATE CAMERELE\n";
  if(camere.empty()){
    std::cout<<"Nicio camera configurata\n";
    return;
  }
  for(const auto& cam : camere){
    std::cout<<*cam;
    std::cout<<"\nStatus: "<<(cam->esteOcupata() ? "ocupata" : "libera")<<"\n";
  }
}

void hotel::afisareCamereLibere() const{
  std::cout<<"\nCAMERE DISPONIBILE:\n";

  bool existaLibere=false;
  for(const auto& cam : camere){
    if(!cam -> esteOcupata()){
      std::cout<<*cam<<"\n";
      existaLibere=true;
    }
  }
  if(!existaLibere)
    std::cout<<"\nNicio camera disponibila\n";
}

int hotel::adaugaClientNou( const std::string& nume, const std::string& prenume, const std::string& parola, const std::string& abonament){
  auto clientNou =std::make_shared<client>(nume, prenume, abonament, parola);
  utilizatori.push_back(clientNou);
  return clientNou->getID();
}

std::shared_ptr<persoana> hotel::identificareUtilizator(int idCautat, const std::string& parolaIntrodusa){
  for(const auto& u : utilizatori){
    if(u-> getID() == idCautat && u->getParola() == parolaIntrodusa)
      return u;
  }
  throw exceptieAutentificareEsuata();
}

void hotel::proceseazaSelectieCamere(int nopti, const std::string& numeClient, const std::string& tipAbonament, const std::vector<int>& numereCamere, const std::vector<std::shared_ptr<serviciu>>& serviciiSuplimentare){
  (void)tipAbonament;
  (void)serviciiSuplimentare;
  if(numereCamere.empty()) {
    throw std::invalid_argument("Selectati minim o camera");
  }

  rezervare rez(numeClient, nopti);
  double costCamere=0.0;

  for(int nrCam: numereCamere){

    try{
      std::shared_ptr<camera> cameraGasita=nullptr;
    for(const auto& cam : camere) {
      if(cam-> getNrCamera() == nrCam){
        cameraGasita=cam;
        break;
      }
    }
    if(cameraGasita==nullptr) throw exceptieCameraInexistenta(nrCam);
    if(cameraGasita->esteOcupata()) throw exceptieCameraDejaOcupata(nrCam);

    rez. adaugaCamera(cameraGasita);
    costCamere+=(nopti*cameraGasita->getPret());
    
  }catch (const exceptieCameraInexistenta& e){
    std::cout<<"\nEroare "<<e.what()<<"\n";
    throw;
  }

  }

  

    double costServicii=0;
    for(const auto& s : serviciiSuplimentare){
      rez.adaugaServiciu(s);
      costServicii+=s->getPret();
    }


    double reducere=0.0;
    if (tipAbonament == "Silver" || tipAbonament == "silver") reducere = 0.10;
    else if (tipAbonament == "Gold" || tipAbonament == "gold") reducere = 0.20;
    
    double costFinal=(costCamere+costServicii) * (1.0- reducere);
    rez.setCostTotal(costFinal);

    for(auto& camAlesa : rez.getCamere()) {
        camAlesa->setStatus(true);
    }
    istoricRezervari.push_back(rez);

    std::cout<<"\nREZUMAT";
    std::cout<<"\nPret cazare: "<<costCamere<<" RON"
             <<"\nPret servicii: "<<costServicii<<" RON"
             <<"\nReducere aplicata: "<<(reducere*100)<<"%"
             <<"\nTotal de plata: "<<costFinal<<" RON\n";
  
}

void hotel::afisareIstoricRezervari() const{
  std::cout<<"\nISTORIC REZERVARI\n";
  if(istoricRezervari.empty()){
    std::cout<<"\nNicio rezervare inregistrata\n";
    return;
  }
  for(const auto& rez : istoricRezervari){
    std::cout<<rez<<"\n";
  }
}

void hotel::afisareTotalIncasari() const{
  double total=0.0;
  for (const auto& rez : istoricRezervari) {
        total += rez.getCostTotal();
  }
  std::cout<<"\nRAPORT INCASARI\n";
  std::cout<<"Nr total rezervari: "<<rezervare::getNrTotalRezervari();
  std::cout<<"\nTotal incasari: "<<total<<" RON";

}