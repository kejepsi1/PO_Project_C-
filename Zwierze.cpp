#include "Zwierze.h"
#include <vector>
#include <cstdlib>
using namespace std;
#include "Swiat.h"

Zwierze::Zwierze(int sila, int inicjatywa, int PolozenieX, int PolozenieY, Swiat* swiat, char znak) :
Organizm(sila,inicjatywa,PolozenieX,PolozenieY, swiat, znak) {}

Zwierze::~Zwierze() = default;

void Zwierze::RozmnozSie() {
    int mozliweX[] = {-1, 1, 0, 0,-1,-1,1,1};
    int mozliweY[] = {0, 0, -1, 1,-1,1,-1,1};
    vector<int> bezpieczne;

    for (int j = 0; j < 8; j++) {
        int potencjalneX = PolozenieX + mozliweX[j];
        int potencjalneY = PolozenieY + mozliweY[j];
        if (potencjalneX >= 0 && potencjalneX < swiat->GetX() && potencjalneY >= 0 && potencjalneY < swiat->GetY()) {
            bool zajete = false;
            for (int i = 0; i < swiat->organizmy.size(); i++) {
                if (swiat->organizmy[i]->GetPolozenieX() == potencjalneX && swiat->organizmy[i]->GetPolozenieY() == potencjalneY) {
                    zajete = true;
                    break;
                }
            }
            if (!zajete) bezpieczne.push_back(j);
        }
    }

    if (!bezpieczne.empty()) {
        int wybrany = rand() % bezpieczne.size();
        int noweX = PolozenieX + mozliweX[bezpieczne[wybrany]];
        int noweY = PolozenieY + mozliweY[bezpieczne[wybrany]];
        Organizm* dziecko = this->Rozmnazaj(noweX, noweY);
        swiat->DodajOrganizm(dziecko);
        string tekst = "Narodzil sie nowy organizm: ";
        tekst += this->GetZnak();
        swiat->DodajKomunikat(tekst);
        dziecko->SetWiek(0);
    }
}