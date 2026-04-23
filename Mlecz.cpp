#include "Mlecz.h"
#include "Roslina.h"
#include "Swiat.h"
#include <iostream>
#include <vector>
#define ZNAK_MLECZA 'M'

Mlecz::Mlecz(int PolozenieX, int PolozenieY, Swiat *swiat) :
Roslina(0,0,PolozenieX, PolozenieY, swiat, ZNAK_MLECZA)
{}

void Mlecz::Rysuj() const {
    swiat->NarysujOrganizm(PolozenieX,PolozenieY,ZNAK_MLECZA);
}

void Mlecz::Akcja() {
    if (this->wiek == 0) {
        return;
    }
    for (int j=0;j<3;j++)
    {
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
                swiat->DodajKomunikat("Powstaje nowy Mlecz");
                swiat->DodajOrganizm(new Mlecz(PolozenieX + mozliweX[bezpieczne[wybrany]],PolozenieY + mozliweY[bezpieczne[wybrany]],swiat));
            }
        }
    }
}

bool Mlecz::CzyMoznaZdeptac(Organizm *napastnik) {
    if (napastnik->CzyDrapieznik()) {
        return true;
    }
    return false;
}
