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

void hotel::proceseazaSelectieCamera(int nrCam, int nopti, const std::string& numeClient){
  std::shared_ptr<camera> cameraGasita=nullptr;

  for(const auto& cam : camere) {
    if(cam->getNrCamera()==nrCam){
      cameraGasita=cam;
      break;
    }
  }
  if(cameraGasita==nullptr){
    throw exceptieCameraInexistenta(nrCam);
  }
  if(cameraGasita->esteOcupata()){
    throw exceptieCameraDejaOcupata(nrCam);

    rezervare rez(numeClient, nopti);

    cameraGasita->setStatus(true);
    istoricRezervari.push_back(rez);
  }
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