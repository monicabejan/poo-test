#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>

class camera {
protected:
    int nrCamera;
    int etaj;
    double pret;
    bool status; // true daca camera e ocupata
public:
    camera(int nr, int et, double p, bool status = false) : nrCamera(nr), etaj(et), pret(p), status(status) {}
    int esteOcupata() const {return status;}
    virtual std::string getTip() const =0;
};


class cameraSingle : public camera{
public:
    cameraSingle(int nr, int et, double p=150.0):camera(nr, et, p) {}
    std::string getTip() const override { return "Single";}

};



#endif