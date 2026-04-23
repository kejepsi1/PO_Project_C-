#ifndef PO_PROJEKT_OWCA_H
#define PO_PROJEKT_OWCA_H
#include "Zwierze.h"


class Owca : public Zwierze{
protected:
    Organizm* Rozmnazaj(int x, int y) override;
public:
    Owca(int PolozenieX, int PolozenieY, Swiat* swiat);
    void Rysuj() const override;
    bool CzyObronil(Organizm *napastnik) override;
};



#endif
