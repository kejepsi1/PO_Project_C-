#include "BarszczSosnowskiego.h"

#include "Roslina.h"
#include "Swiat.h"
#include "Zwierze.h"
#include <iostream>
#include <vector>
#define ZNAK_BARSZCZU_SOSNOWSKIEGO 'B'

BarszczSosnowskiego::BarszczSosnowskiego(int PolozenieX, int PolozenieY, Swiat *swiat) :
Roslina(10,0,PolozenieX, PolozenieY, swiat, ZNAK_BARSZCZU_SOSNOWSKIEGO)
{}

void BarszczSosnowskiego::Rysuj() const {
    swiat->NarysujOrganizm(PolozenieX,PolozenieY,ZNAK_BARSZCZU_SOSNOWSKIEGO);
}

void BarszczSosnowskiego::Akcja() {
    if (this->wiek == 0) {
        return;
    }

    int mozliweX[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int mozliweY[] = {0, 0, -1, 1, -1, 1, -1, 1};

    for (int j = 0; j < 8; j++) {
        int potencjalneX = PolozenieX + mozliweX[j];
        int potencjalneY = PolozenieY + mozliweY[j];

        for (int i = 0; i < swiat->organizmy.size(); i++) {
            Organizm* sasiad = swiat->organizmy[i];

            if (sasiad->GetPolozenieX() == potencjalneX && sasiad->GetPolozenieY() == potencjalneY) {
                if (sasiad->CzyZyje() && dynamic_cast<Zwierze*>(sasiad) != nullptr) {
                    sasiad->Zabij();
                }
            }
        }
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
            swiat->DodajOrganizm(new BarszczSosnowskiego(PolozenieX + mozliweX[bezpieczne[wybrany]],PolozenieY + mozliweY[bezpieczne[wybrany]],swiat));
        }
    }
}



bool BarszczSosnowskiego::SprawdzajSasiadow(int x, int y) {
    for (int i=0;i<swiat->organizmy.size();i++) {
        if (x == swiat->organizmy[i]->GetPolozenieX() && y == swiat->organizmy[i]->GetPolozenieY()) {
            return false;
        }
    }
    return true;
}

bool BarszczSosnowskiego::CzyObronil(Organizm *napastnik) {
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

void BarszczSosnowskiego::Kolizja() {
    swiat->SprawdzajKolizje(this);
}
