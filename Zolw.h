#ifndef PO_PROJEKT_ZOLW_H
#define PO_PROJEKT_ZOLW_H
#include "Zwierze.h"


class Zolw : public Zwierze{
protected:
    Organizm* Rozmnazaj(int x, int y) override;
public:
    Zolw(int PolozenieX, int PolozenieY, Swiat* swiat);
    void Rysuj() const override;
    void Akcja() override;
    bool CzyObronil(Organizm *napastnik) override;
    bool CzyOdpycha(Organizm *napastnik) override;
};



#endif //PO_PROJEKT_ZOLW_H
