#include "Trawa.h"
#include "Roslina.h"
#include "Swiat.h"
#include <iostream>
#include <vector>
#define ZNAK_TRAWY 'T'

Trawa::Trawa(int sila, int inicjatywa, int PolozenieX, int PolozenieY, Swiat *swiat, char znak) :
Roslina(0,0,PolozenieX, PolozenieY, swiat, ZNAK_TRAWY)
{}

void Trawa::Rysuj() const {
    swiat->NarysujOrganizm(PolozenieX,PolozenieY,ZNAK_TRAWY);
}

void Trawa::Akcja() {
    if (this->wiek == 0) {
        return;
    }
    int draw = std::rand() % 10;
    if (draw==0) {
        int mozliweX[] = {-1,1,0,0};
        int mozliweY[] = {0,0,-1,1};
        std::vector<int> bezpieczne;
        for (int i=0;i < 4;i++) {
            int potencjalneX = PolozenieX + mozliweX[i];
            int potencjalneY = PolozenieY + mozliweY[i];

            if (potencjalneX >= 0 && potencjalneX < swiat->GetX() && potencjalneY >=0 && potencjalneY < swiat->GetY()) {
                if (SprawdzajSasiadow(potencjalneX,potencjalneY)) {
                    bezpieczne.push_back(i);
                }
            }
        }

        if (bezpieczne.size() > 0) {
            int wybrany = rand() % bezpieczne.size();
            swiat->DodajOrganizm(new Trawa(0,0,PolozenieX + mozliweX[bezpieczne[wybrany]],PolozenieY + mozliweY[bezpieczne[wybrany]],swiat,ZNAK_TRAWY));
        }
    }
}



bool Trawa::SprawdzajSasiadow(int x, int y) {
    for (int i=0;i<swiat->organizmy.size();i++) {
        if (x == swiat->organizmy[i]->GetPolozenieX() && y == swiat->organizmy[i]->GetPolozenieY()) {
            return false;
        }
    }
    return true;
}

bool Trawa::CzyObronil(Organizm *napastnik) {
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
