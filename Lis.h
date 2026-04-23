#ifndef PO_PROJEKT_LIS_H
#define PO_PROJEKT_LIS_H
#include "Zwierze.h"


class Lis : public Zwierze {
public:
    Lis(int PolozenieX, int PolozenieY, Swiat* swiat);
    void Rysuj() const override;
    void Akcja() override;
    bool DobryWech(int x, int y);
    bool CzyObronil(Organizm *napastnik) override;
    Organizm* Rozmnazaj(int x, int y) override;
    bool CzyDrapieznik() override;
};


#endif
