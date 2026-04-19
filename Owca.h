#ifndef PO_PROJEKT_OWCA_H
#define PO_PROJEKT_OWCA_H
#include "Zwierze.h"


class Owca : public Zwierze{
public:
    Owca(int PolozenieX, int PolozenieY, Swiat* swiat);
    void Rysuj() const override;
    bool CzyObronil(Organizm *napastnik) override;
    Organizm* Rozmnazaj(int x, int y) override;
};



#endif
