#ifndef EXCEPTII_H
#define EXCEPTII_H

#include <stdexcept>
#include <string>
#include <iostream>


class exceptieCameraInexistenta : public std::runtime_error {
public:
    explicit exceptieCameraInexistenta(int nr) : std::runtime_error("\nCamera " + std::to_string(nr) + " nu exista") {}
};

class exceptieCameraDejaOcupata : public std::runtime_error {
public:
    explicit exceptieCameraDejaOcupata(int nr) : std::runtime_error("\nCamera "+ std::to_string(nr) + " este deja ocupata. Alegeti alta") {}
};

class exceptieAutentificareEsuata : public std::runtime_error {
public:
    exceptieAutentificareEsuata() : std::runtime_error("\n ID sau parola incorecte. Incercati din nou") {}
};

#endif