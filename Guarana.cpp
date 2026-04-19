#include "Guarana.h"
#include "Roslina.h"
#include "Swiat.h"
#include <iostream>
#include <vector>
#define ZNAK_GUARANY 'G'

Guarana::Guarana(int PolozenieX, int PolozenieY, Swiat *swiat) :
Roslina(0,0,PolozenieX, PolozenieY, swiat, ZNAK_GUARANY)
{}

void Guarana::Rysuj() const {
    swiat->NarysujOrganizm(PolozenieX,PolozenieY,ZNAK_GUARANY);
}

void Guarana::Akcja() {
    if (this->wiek == 0) {
        return;
    }
    int draw = std::rand() % 20;
    if (draw==0) {
        int mozliweX[] = {-1,1,0,0,-1,-1,1,1};
        int mozliweY[] = {0,0,-1,1,-1,1,-1,1};
        std::vector<int> bezpieczne;
        for (int i=0;i < 8;i++) {
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
            swiat->DodajOrganizm(new Guarana(PolozenieX + mozliweX[bezpieczne[wybrany]],PolozenieY + mozliweY[bezpieczne[wybrany]],swiat));
        }
    }
}



bool Guarana::SprawdzajSasiadow(int x, int y) {
    for (int i=0;i<swiat->organizmy.size();i++) {
        if (x == swiat->organizmy[i]->GetPolozenieX() && y == swiat->organizmy[i]->GetPolozenieY()) {
            return false;
        }
    }
    return true;
}

bool Guarana::CzyObronil(Organizm *napastnik) {
    napastnik->SetSila(napastnik->GetSila() + 3);
    return false;
}

void Guarana::Kolizja() {
    swiat->SprawdzajKolizje(this);
}
