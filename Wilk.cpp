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

bool Wilk::CzyObronil(Organizm *napastnik) {
    if (napastnik->GetSila() == this->GetSila()) {
        if (napastnik->GetWiek() > this->GetWiek()) {
            return false;
        }
        return true;

    }

    if (napastnik->GetSila() > this->GetSila()) {
        return false;
    }
    return true;

}

Organizm *Wilk::Rozmnazaj(int x, int y) {
    return new Wilk(x,y,swiat);
}