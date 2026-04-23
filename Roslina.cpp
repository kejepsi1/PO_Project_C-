#include "Roslina.h"

Roslina::Roslina(int sila, int inicjatywa, int PolozenieX, int PolozenieY, Swiat* swiat, char znak) :
Organizm(sila,inicjatywa,PolozenieX,PolozenieY, swiat, znak) {}

void Roslina::Kolizja() {
    //Tutaj nie implementujemy kolizji, żeby rośliny nie atakowały zwierząt, bo to jest niemożliwe
}

Roslina::~Roslina() = default;