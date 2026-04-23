#include "Czlowiek.h"
#include <iostream>
#include <ncurses.h>
#include "Swiat.h"
#define ZNAK_CZLOWIEKA 'C'
using namespace std;

Czlowiek::Czlowiek(int sila, int inicjatywa, int PolozenieX, int PolozenieY, Swiat* swiat) :
Zwierze(5,4,PolozenieX,PolozenieY, swiat, ZNAK_CZLOWIEKA)
{}

void Czlowiek::Rysuj() const {
    swiat->NarysujOrganizm(PolozenieX,PolozenieY, ZNAK_CZLOWIEKA);
}

void Czlowiek::Akcja() {
    StarePolozenieX = PolozenieX;
    StarePolozenieY = PolozenieY;
    if (czas_trwania_umiejetnosci != 0) {
        czas_trwania_umiejetnosci--;
    }
    if (czas_odnowienia != 0) {
        czas_odnowienia--;
    }
    int klawisz = getch();
    int noweX = PolozenieX;
    int noweY = PolozenieY;
    switch (klawisz) {
        case KEY_UP:
            noweY-=1;
            break;
        case KEY_DOWN:
            noweY+=1;
            break;
        case KEY_LEFT:
            noweX-=1;
            break;
        case KEY_RIGHT:
            noweX+=1;
            break;
        case 'w':
            noweX-=1;
            noweY-=1;
            break;
        case 'r':
            noweX+=1;
            noweY-=1;
            break;
        case 'x':
            noweX-=1;
            noweY+=1;
            break;
        case 'v':
            noweX+=1;
            noweY+=1;
            break;
        case 'u':
            if (czas_odnowienia == 0) {
                swiat->DodajKomunikat("Czlowiek uzywa specjalnej umiejetnosci");
                this->czas_odnowienia = 10;
                this->czas_trwania_umiejetnosci = 5;
            }
            break;
        case 's':
            swiat->ZapiszSwiat();
            break;
        case 'l':
            swiat->SetCzyWczytac(true);
            break;
        case 'q':
            endwin();
            exit(0);
    }
    if (noweX >= 0 && noweX < swiat->GetX() && noweY >=0 && noweY < swiat->GetY()) {
        PolozenieX=noweX;
        PolozenieY=noweY;
    }
}

bool Czlowiek::UniknijSmierci(Organizm *napastnik) {
    if (czas_trwania_umiejetnosci > 0) {
        int mozliweX[] = {-1,1,0,0,-1,-1,1,1};
        int mozliweY[] = {0,0,-1,1,-1,1,-1,1};
        std::vector<int> bezpieczne;

        for (int j=0; j < 8; j++) {
            int potencjalneX = PolozenieX + mozliweX[j];
            int potencjalneY = PolozenieY + mozliweY[j];
            bool found = false;
            if (potencjalneX >= 0 && potencjalneX < swiat->GetX() && potencjalneY >=0 && potencjalneY < swiat->GetY()) {
                for (int i=0; i<swiat->GetOrganizmy().size(); i++) {
                    if (swiat->GetOrganizmy()[i]->GetPolozenieX() == potencjalneX && swiat->GetOrganizmy()[i]->GetPolozenieY() == potencjalneY) {
                        found = true;
                        break;
                    }
                }
                if (!found) bezpieczne.push_back(j);
            }
        }

        if (!bezpieczne.empty()) {
            int wybrany = rand() % bezpieczne.size();
            PolozenieX += mozliweX[bezpieczne[wybrany]];
            PolozenieY += mozliweY[bezpieczne[wybrany]];
            swiat->DodajKomunikat("Czlowiek nie umiera dzieki umiejetnosci i ucieka na sasiednie pole");
            return true;
        }
        else {
            swiat->DodajKomunikat("Czlowiek nie ma gdzie uciec, ale niesmiertelnosc blokuje cios");
            napastnik->Cofnij();
            return true;
        }
    }
    return false;
}

bool Czlowiek::CzyDrapieznik() {
    return true;
}

std::string Czlowiek::DoZapisu() {
    return std::string(1, znak) + " " + std::to_string(PolozenieX) + " " + std::to_string(PolozenieY) + " " + std::to_string(sila) + " " + std::to_string(wiek) + " " + std::to_string(czas_odnowienia) + " " + std::to_string(czas_trwania_umiejetnosci);
}

void Czlowiek::SetCzasOdnowienia(int czas) {
    czas_odnowienia = czas;
}

void Czlowiek::SetCzasTrwaniaUmiejetnosci(int czas) {
    czas_trwania_umiejetnosci = czas;
}
