#ifndef PO_PROJEKT_TRAWA_H
#define PO_PROJEKT_TRAWA_H
#include "Roslina.h"


class Trawa  : public Roslina{
public:
    Trawa(int PolozenieX, int PolozenieY, Swiat* swiat);
    void Rysuj() const override;
    void Akcja() override;
    bool CzyObronil(Organizm *napastnik) override;
    bool CzyMoznaZdeptac(Organizm* napaastnik) override;

};



#endif //PO_PROJEKT_TRAWA_H
