#include <iostream>
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
    swiat->DodajOrganizm(new Czlowiek(5, 4, rand() % x, rand() % y, swiat));
    int ilosc_zwierzat = 3;

    for (int i = 0; i < ilosc_zwierzat; i++) {
        swiat->DodajOrganizm(new Wilk(rand() % x, rand() % y, swiat));
        swiat->DodajOrganizm(new Owca(rand() % x, rand() % y, swiat));
        swiat->DodajOrganizm(new Lis(rand() % x, rand() % y, swiat));
        swiat->DodajOrganizm(new Zolw(rand() % x, rand() % y, swiat));
        swiat->DodajOrganizm(new Antylopa(rand() % x, rand() % y, swiat));

        swiat->DodajOrganizm(new Trawa(rand() % x, rand() % y, swiat));
        swiat->DodajOrganizm(new Mlecz(rand() % x, rand() % y, swiat));
        swiat->DodajOrganizm(new Guarana(rand() % x, rand() % y, swiat));
        swiat->DodajOrganizm(new WilczeJagody(rand() % x, rand() % y, swiat));
    }
    swiat->Graj();
    endwin();
    echo();
    return 0;
}