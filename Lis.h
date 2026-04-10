#ifndef PO_PROJEKT_LIS_H
#define PO_PROJEKT_LIS_H
#include "Zwierze.h"


class Lis : public Zwierze {
public:
    Lis(int sila, int inicjatywa, int PolozenieX, int PolozenieY, Swiat* swiat, char znak);
    void Rysuj() const override;
    void Akcja() override;
    bool DobryWech(int x, int y);
    bool CzyObronil(Organizm *napastnik) override;

};


#endif
