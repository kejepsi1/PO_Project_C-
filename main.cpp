#include <iostream>
#include "Swiat.h"
#include "Czlowiek.h"
#include "Wilk.h"
#include "Lis.h"
#include "Owca.h"
#include <ncurses.h>
#include "Zolw.h"
#include "Antylopa.h"
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
    Swiat* swiat = new Swiat(x,y);
    Organizm* czlowiek = new Czlowiek(5,4,5,5, swiat, 'C');
    Organizm* wilk = new Wilk(9,5,3,3, swiat, 'W');
    Organizm* owca = new Owca(4,4,10,10,swiat, 'O');
    Organizm* lis = new Lis(3,7,4,4,swiat,'L');
    Organizm* zolw = new Zolw(2,1,3,3,swiat, 'Z');
    Organizm* antylopa = new Antylopa(4,4,5,5,swiat,'A');
    swiat->DodajOrganizm(czlowiek);
    swiat->DodajOrganizm(wilk);
    swiat->DodajOrganizm(owca);
    swiat->DodajOrganizm(lis);
    swiat->DodajOrganizm(zolw);
    swiat->DodajOrganizm(antylopa);
    swiat->Graj();
    endwin();
    echo();
    return 0;
}