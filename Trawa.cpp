#include "Trawa.h"
#include "Roslina.h"
#include "Swiat.h"
#define ZNAK_TRAWY 'T'

Trawa::Trawa(int sila, int inicjatywa, int PolozenieX, int PolozenieY, Swiat *swiat, char znak) :
Roslina(0,0,PolozenieX, PolozenieY, swiat, ZNAK_TRAWY)
{}

void Trawa::Rysuj() const {
    swiat->NarysujOrganizm(PolozenieX,PolozenieY,ZNAK_TRAWY);
}
