#ifndef PO_PROJEKT_OWCA_H
#define PO_PROJEKT_OWCA_H
#include "Zwierze.h"


class Owca : public Zwierze{
public:
    Owca(int sila, int inicjatywa, int PolozenieX, int PolozenieY, Swiat* swiat, char znak);
    void Rysuj() const override;
    bool CzyObronil(Organizm *napastnik) override;
};



#endif
