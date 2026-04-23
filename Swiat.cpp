#include "Swiat.h"
#include "Organizm.h"
#include "Czlowiek.h"
#include "Wilk.h"
#include <iostream>
#include <ncurses.h>
#include <vector>
#include <algorithm>
#include <fstream>

#include "Antylopa.h"
#include "BarszczSosnowskiego.h"
#include "Guarana.h"
#include "Lis.h"
#include "Mlecz.h"
#include "Owca.h"
#include "Trawa.h"
#include "WilczeJagody.h"
#include "Zolw.h"
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
    clear();
    for (int i=0;i<y;i++) {
        for (int j=0;j<x;j++) {
            mvaddch(i,j,'#');
        }
    }
    for (int i=organizmy.size() - 1; i >= 0;i--) {
        if (organizmy[i]->CzyZyje()) {
            organizmy[i]->Rysuj();
        }
    }
    mvprintw(this->y, 0, "Mikolaj Tchorek 208435");
    int pierwszaLiniaLogow = this->y + 3;
    mvprintw(pierwszaLiniaLogow - 1, 0, "--- RAPORT Z TURY ---");

    for (int i = 0; i < komunikaty.size(); i++) {
        mvprintw(pierwszaLiniaLogow + i, 0, "%s", komunikaty[i].c_str());
    }

    refresh();

}

void Swiat::DodajBezpiecznieOrganizm(Organizm *organizm) {
    if (organizmy.size() >= x * y) {
        delete organizm;
        return;
    }

    bool zajete;
    int randX, randY;
    do {
        zajete = false;
        randX = rand() % x;
        randY = rand() % y;

        for(int i = 0; i < organizmy.size(); i++) {
            if (organizmy[i]->GetPolozenieX() == randX && organizmy[i]->GetPolozenieY() == randY) {
                zajete = true;
                break;
            }
        }
    } while(zajete);

    organizm->SetPolozenieX(randX);
    organizm->SetPolozenieY(randY);
    this->DodajOrganizm(organizm);
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
            RysujSwiat();
            mvprintw(this->y + 1, 0, "Koniec Gry, Czlowiek umarl");
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
    komunikaty.clear();

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

    if (czyWczytac) {
        WczytajSwiat();
        czyWczytac = false;
    }
}

void Swiat::SprawdzajKolizje(Organizm* napastnik) {
    for (int i=0;i<organizmy.size();i++) {
        Organizm* obronca = organizmy[i];
        if (obronca == napastnik || !obronca->CzyZyje() || !napastnik->CzyZyje()) {
            continue;
        }

        if (obronca->GetPolozenieX() == napastnik->GetPolozenieX() && obronca->GetPolozenieY() == napastnik->GetPolozenieY()){
            if (obronca->CzyMoznaZdeptac(napastnik)) {
                continue;
            }
            if (obronca->GetZnak() == napastnik->GetZnak()) {
                napastnik->Cofnij();
                obronca->RozmnozSie();
                return;
            }
            if (organizmy[i]->CzyOdpycha(napastnik) == false) {
                if (organizmy[i]->CzyObronil(napastnik) == false) {
                    if (obronca->UniknijSmierci(napastnik)) {
                        return;
                    }
                    string tekst = string(1, napastnik->GetZnak()) + " zjada " + string(1, obronca->GetZnak());
                    DodajKomunikat(tekst);
                    obronca->Zabij();
                    return;
                }
                else {
                    if (napastnik->UniknijSmierci(obronca)) {
                        return;
                    }
                    string tekst = string(1, obronca->GetZnak()) + " zjada " + string(1, napastnik->GetZnak());
                    DodajKomunikat(tekst);
                    napastnik->Zabij();
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

void Swiat::DodajKomunikat(std::string komunikat) {
    komunikaty.push_back(komunikat);
}

void Swiat::ZapiszSwiat() {
    std::ofstream plik("../zapis.txt");

    if (plik.is_open()) {
        plik << x << " " << y << std::endl;
        for (int i = 0; i < organizmy.size(); i++) {
            if (organizmy[i]->CzyZyje()) {
                plik << organizmy[i]->DoZapisu() << std::endl;
            }
        }
        plik.close();
        DodajKomunikat("Stan gry zostal pomyslnie zapisany!");
    } else {
        DodajKomunikat("Blad: Nie udalo sie otworzyc pliku do zapisu!");
    }
}

void Swiat::WczytajSwiat() {
    std::ifstream plik("../zapis.txt");
    if (!plik.is_open()) {
        DodajKomunikat("Blad: Nie znaleziono pliku zapisu");
        return;
    }

    for (int i = 0;i < organizmy.size();i++) {
        delete organizmy[i];
    }
    organizmy.clear();
    komunikaty.clear();

    plik >> x >> y;
    char znak;
    int sila, polozenieX, polozenieY, wiek;
    while (plik >> znak >> polozenieX >> polozenieY >> sila >> wiek) {
        Organizm* nowy = nullptr;
        if (znak == 'W') nowy = new Wilk(polozenieX,polozenieY,this);
        else if (znak == 'O') nowy = new Owca(polozenieX, polozenieY, this);
        else if (znak == 'L') nowy = new Lis(polozenieX, polozenieY, this);
        else if (znak == 'Z') nowy = new Zolw(polozenieX, polozenieY, this);
        else if (znak == 'A') nowy = new Antylopa(polozenieX, polozenieY, this);
        else if (znak == 'T') nowy = new Trawa(polozenieX, polozenieY, this);
        else if (znak == 'M') nowy = new Mlecz(polozenieX, polozenieY, this);
        else if (znak == 'G') nowy = new Guarana(polozenieX, polozenieY, this);
        else if (znak == 'J') nowy = new WilczeJagody(polozenieX, polozenieY, this);
        else if (znak == 'B') nowy = new BarszczSosnowskiego(polozenieX, polozenieY, this);
        else if (znak == 'C') {
            Czlowiek* c = new Czlowiek(0, 0, polozenieX, polozenieY, this);
            int odnowienie, trwanie;
            plik >> odnowienie >> trwanie;
            c->SetCzasOdnowienia(odnowienie);
            c->SetCzasTrwaniaUmiejetnosci(trwanie);
            nowy = c;
        }

        if (nowy != nullptr) {
            nowy->SetSila(sila);
            nowy->SetWiek(wiek);
            DodajOrganizm(nowy);
        }
    }
    plik.close();
    DodajKomunikat("Gra zostala wczytana pomyslnie");
}

Swiat::~Swiat() {
    for (int i=0;i<organizmy.size();i++) {
        delete organizmy[i];
    }
    organizmy.clear();
}