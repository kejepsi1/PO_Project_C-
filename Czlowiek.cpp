#include "Czlowiek.h"
#include <iostream>
#include <ncurses.h>
#include "Swiat.h"
#define ZNAK_CZLOWIEKA 'C'
using namespace std;

Czlowiek::Czlowiek(int sila, int inicjatywa, int PolozenieX, int PolozenieY, Swiat* swiat) :
Zwierze(5,4,PolozenieX,PolozenieY, swiat, ZNAK_CZLOWIEKA)
{}

void Czlowiek::Rysuj() const {
    swiat->NarysujOrganizm(PolozenieX,PolozenieY, ZNAK_CZLOWIEKA);
}

void Czlowiek::Akcja() {
    int klawisz = getch();
    int noweX = PolozenieX;
    int noweY = PolozenieY;
    switch (klawisz) {
        case KEY_UP:
            noweY-=1;
            break;
        case KEY_DOWN:
            noweY+=1;
            break;
        case KEY_LEFT:
            noweX-=1;
            break;
        case KEY_RIGHT:
            noweX+=1;
            break;
        case 'q':
            endwin();
            exit(0);
    }
    if (noweX >= 0 && noweX < swiat->GetX() && noweY >=0 & noweY < swiat->GetY()) {
        PolozenieX=noweX;
        PolozenieY=noweY;
    }
}

bool Czlowiek::CzyObronil(Organizm *napastnik) {
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
