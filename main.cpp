fi#include <iostream>
#include <ctime>
#include "Swiat.h"
#include "Czlowiek.h"
#include "Wilk.h"
#include "Lis.h"
#include "Owca.h"
#include <ncurses.h>
#include "Zolw.h"
#include "Antylopa.h"
#include "Guarana.h"
#include "Mlecz.h"
#include "Trawa.h"
#include "WilczeJagody.h"
#include "BarszczSosnowskiego.h"
using namespace std;

int main() {
    int x,y;
    cout << "Podaj wymiar x świata: ";
    cin >> x;
    cout << "Podaj wymiar y świata: ";
    cin >> y;
    initscr();
    keypad(stdscr, TRUE);
    curs_set(0);
    noecho();
    cbreak();
    srand(time(NULL));
    Swiat* swiat = new Swiat(x,y);
    swiat->DodajBezpiecznieOrganizm(new Czlowiek(5, 4, 0, 0, swiat));
    int ilosc_zwierzat = 5;
    int ilosc_roslin = 3;

    for (int i = 0; i < ilosc_zwierzat; i++) {
        swiat->DodajBezpiecznieOrganizm(new Wilk(0,0, swiat));
        swiat->DodajBezpiecznieOrganizm(new Owca(0,0, swiat));
        swiat->DodajBezpiecznieOrganizm(new Lis(0,0, swiat));
        swiat->DodajBezpiecznieOrganizm(new Zolw(0,0, swiat));
        swiat->DodajBezpiecznieOrganizm(new Antylopa(0,0, swiat));
    }

    for (int i = 0; i < ilosc_roslin; i++) {
        swiat->DodajBezpiecznieOrganizm(new Trawa(0,0, swiat));
        swiat->DodajBezpiecznieOrganizm(new Mlecz(0,0, swiat));
        swiat->DodajBezpiecznieOrganizm(new Guarana(0,0, swiat));
        swiat->DodajBezpiecznieOrganizm(new WilczeJagody(0,0, swiat));
        swiat->DodajBezpiecznieOrganizm(new BarszczSosnowskiego(0,0, swiat));
    }
    swiat->Graj();
    endwin();
    echo();
    delete swiat;
    return 0;
}