#include "Roslina.h"
#include "Swiat.h"

Roslina::Roslina(int sila, int inicjatywa, int PolozenieX, int PolozenieY, Swiat* swiat, char znak) :
Organizm(sila,inicjatywa,PolozenieX,PolozenieY, swiat, znak) {}

void Roslina::Kolizja() {
    //Tutaj nie implementujemy kolizji, żeby rośliny nie atakowały zwierząt, bo to jest niemożliwe
}

bool Roslina::SprawdzajSasiadow(int x, int y) {
    for (int i=0;i<swiat->GetOrganizmy().size();i++) {
        if (swiat->GetOrganizmy()[i]->CzyZyje() && x == swiat->GetOrganizmy()[i]->GetPolozenieX() && y == swiat->GetOrganizmy()[i]->GetPolozenieY()) {
            return false;
        }
    }
    return true;
}
Roslina::~Roslina() = default;