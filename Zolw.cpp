#include "Zolw.h"
#include <iostream>

#include "Swiat.h"
#define ZNAK_ZOLWIA 'Z'
using namespace std;

Zolw::Zolw(int PolozenieX, int PolozenieY, Swiat* swiat) :
Zwierze(2,1,PolozenieX,PolozenieY, swiat, ZNAK_ZOLWIA)
{}

void Zolw::Rysuj() const {
    swiat->NarysujOrganizm(PolozenieX,PolozenieY, ZNAK_ZOLWIA);
}

void Zolw::Akcja() {
    if (this->wiek == 0) {
        return;
    }
    int noweX = PolozenieX;
    int noweY = PolozenieY;
    int ruch = rand() % 4;
    int czyrusza = rand() % 4;
    switch (czyrusza) {
        case 0:
        case 1:
        case 2:
            break;
        case 3:
            switch (ruch) {
            case 0:
                    noweX+=1;
                    break;
            case 1:
                    noweX-=1;
                    break;
            case 2:
                    noweY+=1;
                    break;
            case 3:
                    noweY-=1;
                    break;
            }
            if (noweX >= 0 && noweX < swiat->GetX() && noweY >=0 & noweY < swiat->GetY()) {
                PolozenieX=noweX;
                PolozenieY=noweY;
            }
    }
}

bool Zolw::CzyOdpycha(Organizm *napastnik) {
    if (napastnik->GetSila() < 5) {
        napastnik->Cofnij();
        return true;
    }
    return false;
}

bool Zolw::CzyObronil(Organizm *napastnik) {
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

Organizm* Zolw::Rozmnazaj(int x,int y) {
    return new Zolw(x,y,swiat);
}