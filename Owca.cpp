#include "Owca.h"
#include <iostream>
#include <ncurses.h>

#include "Swiat.h"
#define ZNAK_OWCY 'O'
using namespace std;

Owca::Owca(int PolozenieX, int PolozenieY, Swiat* swiat, char znak) :
Zwierze(4,4,PolozenieX,PolozenieY, swiat, ZNAK_OWCY)
{}

void Owca::Rysuj() const {
    swiat->NarysujOrganizm(PolozenieX,PolozenieY, ZNAK_OWCY);
}

bool Owca::CzyObronil(Organizm *napastnik) {
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

Organizm *Owca::Rozmnazaj(int x, int y) {
    return new Owca(x,y,swiat,ZNAK_OWCY);
}