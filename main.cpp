#include <iostream>
#include "hotel.h"
#include "persoana.h"

int main() {
    hotel *h = hotel::getInstanta();
    h->doarAsa();
    persoana p;
    p.doSomething();
    return 0;
}
