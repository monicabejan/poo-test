#include <iostream>
#include "hotel.h"
#include "persoana.h"
#include "camera.h"

int main() {
    hotel *h = hotel::getInstanta();
    h->doarAsa();
    persoana p(1,"ana","maria");
    int i=p.getID();
    std::cout<<i;
    camera c(1,1,1);
    std::cout<<c.esteOcupata();
    return 0;
}
