#include "Lis.h"
#include <iostream>
#include "Swiat.h"
#define ZNAK_LISA 'L'
using namespace std;

Lis::Lis(int PolozenieX, int PolozenieY, Swiat* swiat) :
Zwierze(3,7,PolozenieX,PolozenieY, swiat, ZNAK_LISA)
{}

void Lis::Rysuj() const {
    swiat->NarysujOrganizm(PolozenieX,PolozenieY, ZNAK_LISA);
}

void Lis::Akcja() {
    if (this->wiek == 0) {
        return;
    }
    int mozliweX[] = {-1,1,0,0,-1,-1,1,1};
    int mozliweY[] = {0,0,-1,1,-1,1,-1,1};
    std::vector<int> bezpieczne;
    for (int i=0;i < 8;i++) {
        int potencjalneX = PolozenieX + mozliweX[i];
        int potencjalneY = PolozenieY + mozliweY[i];

        if (potencjalneX >= 0 && potencjalneX < swiat->GetX() && potencjalneY >=0 && potencjalneY < swiat->GetY()) {
            if (DobryWech(potencjalneX,potencjalneY)) {
                bezpieczne.push_back(i);
            }
        }
    }
    
    if (bezpieczne.size() > 0) {
        StarePolozenieX = PolozenieX;
        StarePolozenieY = PolozenieY;
        int wybrany = rand() % bezpieczne.size();
        PolozenieX+= mozliweX[bezpieczne[wybrany]];
        PolozenieY+= mozliweY[bezpieczne[wybrany]];
    }
}

bool Lis::DobryWech(int x, int y) {
    for (int i=0;i<swiat->organizmy.size();i++) {
        if (x == swiat->organizmy[i]->GetPolozenieX() && y == swiat->organizmy[i]->GetPolozenieY()) {
            if (sila < swiat->organizmy[i]->GetSila()) {
                return false;
            }
        }
    }
    return true;
}

bool Lis::CzyObronil(Organizm *napastnik) {
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

Organizm *Lis::Rozmnazaj(int x, int y) {
    return new Lis(x,y,swiat);
}

bool Lis::CzyDrapieznik() {
    return true;
}
