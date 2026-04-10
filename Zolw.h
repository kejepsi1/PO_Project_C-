#ifndef PO_PROJEKT_ZOLW_H
#define PO_PROJEKT_ZOLW_H
#include "Zwierze.h"


class Zolw : public Zwierze{
public:
    Zolw(int sila, int inicjatywa, int PolozenieX, int PolozenieY, Swiat* swiat, char znak);
    void Rysuj() const override;
    void Akcja() override;
    void Kolizja() override;
    bool CzyObronil(Organizm *napastnik) override;
    bool CzyOdpycha(Organizm *napastnik) override;
};



#endif //PO_PROJEKT_ZOLW_H
