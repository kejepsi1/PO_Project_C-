#include "Wilk.h"
#include <iostream>
#include "Swiat.h"
#define ZNAK_WILKA 'W'
using namespace std;

Wilk::Wilk(int PolozenieX, int PolozenieY, Swiat* swiat) :
Zwierze(9,5,PolozenieX,PolozenieY, swiat, ZNAK_WILKA)
{}

void Wilk::Rysuj() const {
    swiat->NarysujOrganizm(PolozenieX,PolozenieY, ZNAK_WILKA);
}

Organizm *Wilk::Rozmnazaj(int x, int y) {
    return new Wilk(x,y,swiat);
}

bool Wilk::CzyDrapieznik() {
    return true;
}
