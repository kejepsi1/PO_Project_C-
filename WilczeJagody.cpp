#include "WilczeJagody.h"

#include "Roslina.h"
#include "Swiat.h"
#include <iostream>
#include <vector>
#define ZNAK_WILCZYCH_JAGOD 'J'

WilczeJagody::WilczeJagody(int PolozenieX, int PolozenieY, Swiat *swiat) :
Roslina(99,0,PolozenieX, PolozenieY, swiat, ZNAK_WILCZYCH_JAGOD)
{}

void WilczeJagody::Rysuj() const {
    swiat->NarysujOrganizm(PolozenieX,PolozenieY,ZNAK_WILCZYCH_JAGOD);
}

void WilczeJagody::Akcja() {
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
            swiat->DodajKomunikat("Powstaja nowe Wilcze Jagody");
            swiat->DodajOrganizm(new WilczeJagody(PolozenieX + mozliweX[bezpieczne[wybrany]],PolozenieY + mozliweY[bezpieczne[wybrany]],swiat));
        }
    }
}

bool WilczeJagody::CzyObronil(Organizm *napastnik) {
    this->Zabij();
    std::string tekst = "Wilcze Jagody zabijaja organizm: ";
    tekst += napastnik->GetZnak();
    swiat->DodajKomunikat(tekst);
    return true;
}