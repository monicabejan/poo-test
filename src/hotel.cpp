#include "../include/hotel.h"

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
  return nullptr;
}