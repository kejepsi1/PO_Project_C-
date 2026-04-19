#include "Antylopa.h"
#include <iostream>
#include "Swiat.h"
#define ZNAK_ANTYLOPY 'A'
using namespace std;

Antylopa::Antylopa(int PolozenieX, int PolozenieY, Swiat* swiat) :
Zwierze(4,4,PolozenieX,PolozenieY, swiat, ZNAK_ANTYLOPY)
{}

void Antylopa::Rysuj() const {
    swiat->NarysujOrganizm(PolozenieX,PolozenieY, ZNAK_ANTYLOPY);
}

void Antylopa::Akcja() {
    int noweX = PolozenieX;
    int noweY = PolozenieY;
    int ruch = rand() % 4;
    int ilepol = rand() % 2;
    switch (ilepol) {
        case 0:
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
            if (noweX >= 0 && noweX < swiat->GetX() && noweY >=0 & noweY < swiat->GetY()) {
                PolozenieX=noweX;
                PolozenieY=noweY;
            }
            break;
        case 1:
            switch (ruch) {
            case 0:
                    noweX+=2;
                    break;
            case 1:
                    noweX-=2;
                    break;
            case 2:
                    noweY+=2;
                    break;
            case 3:
                    noweY-=2;
                    break;
            }
            if (noweX >= 0 && noweX < swiat->GetX() && noweY >=0 & noweY < swiat->GetY()) {
                PolozenieX=noweX;
                PolozenieY=noweY;
            }
    }
}

void Antylopa::Kolizja() {
    swiat->SprawdzajKolizje(this);
}

bool Antylopa::CzyOdpycha(Organizm *napastnik) {
    int losuj = rand() % 2;
    if (losuj==0) {
        return false;
    }
    int mozliweX[] = {-1,1,0,0};
    int mozliweY[] = {0,0,-1,1};
    vector<int> bezpieczne;
    for (int j=0;j<4;j++) {
        int potencjalneX = PolozenieX + mozliweX[j];
        int potencjalneY = PolozenieY + mozliweY[j];
        bool found = false;
        if (potencjalneX >= 0 && potencjalneX < swiat->GetX() && potencjalneY >=0 && potencjalneY < swiat->GetY()) {
            for (int i=0;i<swiat->organizmy.size();i++) {
                if (swiat->organizmy[i]->GetPolozenieX() == potencjalneX && swiat->organizmy[i]->GetPolozenieY() == potencjalneY) {
                    found = true;
                    break;
                }
            }
            if (!found)
                bezpieczne.push_back(j);
        }
    }
    if (!bezpieczne.empty()) {
        int wybrany = rand() % bezpieczne.size();
        PolozenieX+= mozliweX[wybrany];
        PolozenieY+= mozliweY[wybrany];
        return true;
    }
    return false;
}

bool Antylopa::CzyObronil(Organizm *napastnik) {
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

Organizm *Antylopa::Rozmnazaj(int x, int y) {
    return new Antylopa(x,y,swiat);
}
