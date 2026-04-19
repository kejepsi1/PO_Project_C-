#include "Swiat.h"
#include "Organizm.h"
#include "Czlowiek.h"
#include <iostream>
#include <ncurses.h>
#include <vector>
#include <algorithm>
using namespace std;

Swiat::Swiat(int x,int y) {
    this->x=x;
    this->y=y;
}

void Swiat::NarysujOrganizm(int PolozenieX, int PolozenieY, char znak) {
    mvaddch(PolozenieY,PolozenieX,znak);
}

int Swiat::GetX() const {
    return x;
}

int Swiat::GetY() const {
    return y;
}

void Swiat::SetX(int x) {
    this->x=x;
}

void Swiat::SetY(int y) {
    this->y=y;
}

void Swiat::RysujSwiat() {
    for (int i=0;i<y;i++) {
        for (int j=0;j<x;j++) {
            mvaddch(i,j,'#');
        }
    }
    for (int i=0; i<organizmy.size();i++) {
        organizmy[i]->Rysuj();
    }

    refresh();

}

void Swiat::DodajOrganizm(Organizm *organizm) {
    organizmy.push_back(organizm);
}

void Swiat::Graj() {
    while (true) {
        WykonajTure();

        bool CzlowiekZyje = false;

        for (int i=0;i<organizmy.size();i++) {
            if (dynamic_cast<Czlowiek*>(organizmy[i]) != nullptr) {
                CzlowiekZyje = true;
                break;
            }
        }
        if (CzlowiekZyje == false) {
            mvprintw(0,0, "Koniec Gry, Czlowiek umarl");
            refresh();
            getch();
            endwin();
            return;
        }
    }
}

void Swiat::WykonajTure() {
    std::sort(organizmy.begin(),organizmy.end(), [](Organizm* a, Organizm* b) {
        if (a->GetInicjatywa() == b->GetInicjatywa()) {
            return a->GetWiek() > b->GetWiek();
        }
        return a->GetInicjatywa() > b->GetInicjatywa();
    });

    RysujSwiat();

    for (int i=0;i<organizmy.size();i++) {
        if (organizmy[i]->CzyZyje()) {
            organizmy[i]->Akcja();
            organizmy[i]->Kolizja();
        }
    }

    for (int i = 0;i < organizmy.size();i++) {
        if (!organizmy[i]->CzyZyje()) {
            delete organizmy[i];
            organizmy.erase(organizmy.begin() + i);
            i--;
        }
    }
    DodajWiek();
}

void Swiat::SprawdzajKolizje(Organizm* napastnik) {
    for (int i=0;i<organizmy.size();i++) {
        Organizm* obronca = organizmy[i];
        if (obronca == napastnik) {
            continue;
        }
        if (obronca->GetPolozenieX() == napastnik->GetPolozenieX() && obronca->GetPolozenieY() == napastnik->GetPolozenieY()){
            if (obronca->GetZnak() == napastnik->GetZnak()) {
                napastnik->Cofnij();
                obronca->RozmnozSie();
                return;
            }
            if (organizmy[i]->CzyOdpycha(napastnik) == false) {
                if (organizmy[i]->CzyObronil(napastnik) == false) {
                    delete obronca;
                    organizmy.erase(organizmy.begin() + i);
                    return;
                }
                else {
                    for (int j=0;j<organizmy.size();j++) {
                        if (organizmy[j] == napastnik) {
                            organizmy.erase(organizmy.begin() + j);
                            break;
                        }
                    }
                    delete napastnik;
                    return;
                }
            }
            else {
                return;
            }
        }
    }
}

void Swiat::DodajWiek() {
    for (int i=0;i<organizmy.size();i++) {
        organizmy[i]->SetWiek(organizmy[i]->GetWiek() + 1);
    }
}

Swiat::~Swiat() {
    for (int i=0;i<organizmy.size();i++) {
        delete organizmy[i];
    }
    organizmy.clear();
}