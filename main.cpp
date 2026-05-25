#include <iostream>
#include "hotel.h"
#include "persoana.h"

int main() {
    hotel *h = hotel::getInstanta();
    h->doarAsa();
    persoana p;
    int i=p.getId();
    return 0;
}
