#ifndef PO_PROJEKT_ANTYLOPA_H
#define PO_PROJEKT_ANTYLOPA_H
#include "Zwierze.h"


class Antylopa : public Zwierze{
public:
    Antylopa(int PolozenieX, int PolozenieY, Swiat* swiat, char znak);
    void Rysuj() const override;
    void Akcja() override;
    void Kolizja() override;
    bool CzyObronil(Organizm *napastnik) override;
    bool CzyOdpycha(Organizm *napastnik) override;
    Organizm* Rozmnazaj(int x, int y) override;
};



#endif //PO_PROJEKT_ANTYLOPA_H
