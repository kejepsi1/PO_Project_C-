#ifndef PO_PROJEKT_SWIAT_H
#define PO_PROJEKT_SWIAT_H
#include <string>
#include <vector>
#include "Organizm.h"
#include <string>

class Swiat {
private:
    int x,y;
    std::vector<Organizm*> organizmy;
    std::vector<std::string> komunikaty;
    bool czyWczytac = false;
    void DodajWiek();
    void WczytajSwiat();
public:
    const std::vector<Organizm*>& GetOrganizmy() const;
    void SetCzyWczytac(bool stan);
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
    void DodajKomunikat(std::string komunikat);
    void ZapiszSwiat();
};


#endif