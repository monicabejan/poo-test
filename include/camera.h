#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>

class camera {
protected:
    int nrCamera;
    int etaj;
    double pret;
    bool status; 
public:
    camera(int nr, int et, double p, bool status = false);
    camera(const camera& other);
    camera& operator=(const camera& other);
    virtual ~camera()=default;

    int esteOcupata() const {return status;}
    int getNrCamera() const {return nrCamera;}
    void setStatus(bool st){status=st;}
    double getPret() const { return pret;}
    virtual std::string getTip() const =0;
    virtual void afisareDetalii (std::ostream& os) const =0;

    friend std::ostream& operator<<(std::ostream& os, const camera& c); 
};



class cameraSingle : public camera{
public:
    cameraSingle(int nr, int et, double p=150.0);
    cameraSingle(const cameraSingle& other);
    cameraSingle& operator=(const cameraSingle& other);
   
    std::string getTip() const override { return "Single";}
    void afisareDetalii(std::ostream& os) const override;
};



class cameraDouble : public camera{
    std::string tipConfiguratie;
public:
    cameraDouble(int nr, int et, const std::string& config, double p=250.0) ;
    cameraDouble(const cameraDouble& other);
    cameraDouble& operator=(const cameraDouble& other);
    
    std::string getTip() const override { return "Double";}
    const std::string& getConfiguratie() const {return tipConfiguratie;}
    void afisareDetalii(std::ostream& os) const override;
};

class penthouse: public camera {
    int nrDormitoare;
public:
    penthouse(int nr, int et, int nrDorm, double p=500.0);
    penthouse(const penthouse& other);
    penthouse& operator=(const penthouse& other);
    
    std::string getTip() const override {return "Penthouse";}
    int getDormitoare() const {return nrDormitoare;}
    void afisareDetalii(std::ostream& os) const override;
};

#endif