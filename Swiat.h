#ifndef PO_PROJEKT_SWIAT_H
#define PO_PROJEKT_SWIAT_H
#include <vector>
#include "Organizm.h"

class Swiat {
private:
    int x,y;
public:
    std::vector<Organizm*> organizmy;
    Swiat(int x, int y);
    ~Swiat();
    void SetX(int x);
    void SetY(int y);
    int GetX() const;
    int GetY() const;
    void RysujSwiat();
    void DodajOrganizm(Organizm* organizm);
    void NarysujOrganizm(int PolozenieX, int PolozenieY, char znak);
    void WykonajTure();
    void Graj();
    void SprawdzajKolizje(Organizm* organizm);
    void DodajWiek();
};


#endif