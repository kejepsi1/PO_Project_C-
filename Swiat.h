#ifndef PO_PROJEKT_SWIAT_H
#define PO_PROJEKT_SWIAT_H
#include <string>
#include <vector>
#include "Organizm.h"
#include <string>

class Swiat {
private:
    int x,y;
public:
    std::vector<Organizm*> organizmy;
    std::vector<std::string> komunikaty;
    bool czyWczytac = false;
    Swiat(int x, int y);
    ~Swiat();
    void SetX(int x);
    void SetY(int y);
    int GetX() const;
    int GetY() const;
    void RysujSwiat();
    void DodajBezpiecznieOrganizm(Organizm* organizm);
    void DodajOrganizm(Organizm* organizm);
    void NarysujOrganizm(int PolozenieX, int PolozenieY, char znak);
    void WykonajTure();
    void Graj();
    void SprawdzajKolizje(Organizm* organizm);
    void DodajWiek();
    void DodajKomunikat(std::string komunikat);
    void ZapiszSwiat();
    void WczytajSwiat();
};


#endif