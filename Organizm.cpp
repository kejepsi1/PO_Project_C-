#include "Organizm.h"

#include <cstdlib>

#include "Swiat.h"

Organizm::Organizm(int sila, int inicjatywa, int PolozenieX, int PolozenieY, Swiat* swiat, char znak) {
    this->sila=sila;
    this->inicjatywa=inicjatywa;
    this->PolozenieX=PolozenieX;
    this->PolozenieY=PolozenieY;
    this->swiat=swiat;
    this->znak=znak;
    this->wiek=0;
}

int Organizm::GetSila() const {
    return sila;
}

int Organizm::GetInicjatywa() const {
    return inicjatywa;
}

int Organizm::GetPolozenieX() const {
    return PolozenieX;
}

int Organizm::GetPolozenieY() const {
    return PolozenieY;
}

char Organizm::GetZnak() const {
    return znak;
}

int Organizm::GetWiek() const {
    return wiek;
}

bool Organizm::CzyOdpycha(Organizm *napastnik) {
    return false;
}

void Organizm::Akcja() {
    if (this->wiek == 0) {
        return;
    }
    int noweX = PolozenieX;
    int noweY = PolozenieY;
    int ruch = rand() % 4;
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
    if (noweX >= 0 && noweX < swiat->GetX() && noweY >=0 && noweY < swiat->GetY()) {
        StarePolozenieX=PolozenieX;
        StarePolozenieY=PolozenieY;
        PolozenieX=noweX;
        PolozenieY=noweY;
    }
}

void Organizm::Kolizja() {
    swiat->SprawdzajKolizje(this);
}


void Organizm::Cofnij() {
    PolozenieX=StarePolozenieX;
    PolozenieY=StarePolozenieY;
}

Organizm::~Organizm() = default;
