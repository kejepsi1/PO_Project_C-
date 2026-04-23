#ifndef PO_PROJEKT_LIS_H
#define PO_PROJEKT_LIS_H
#include "Zwierze.h"


class Lis : public Zwierze {
protected:
    Organizm* Rozmnazaj(int x, int y) override;
public:
    Lis(int PolozenieX, int PolozenieY, Swiat* swiat);
    void Rysuj() const override;
    void Akcja() override;
    bool DobryWech(int x, int y);
    bool CzyDrapieznik() override;
};


#endif
