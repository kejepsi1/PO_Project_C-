#include "Roslina.h"
#include "Swiat.h"

Roslina::Roslina(int sila, int inicjatywa, int PolozenieX, int PolozenieY, Swiat* swiat, char znak) :
Organizm(sila,inicjatywa,PolozenieX,PolozenieY, swiat, znak) {}

void Roslina::Kolizja() {
    //Tutaj nie implementujemy kolizji, żeby rośliny nie atakowały zwierząt, bo to jest niemożliwe
}

bool Roslina::SprawdzajSasiadow(int x, int y) {
    for (int i=0;i<swiat->organizmy.size();i++) {
        if (swiat->organizmy[i]->CzyZyje() && x == swiat->organizmy[i]->GetPolozenieX() && y == swiat->organizmy[i]->GetPolozenieY()) {
            return false;
        }
    }
    return true;
}
Roslina::~Roslina() = default;