
#ifndef PO_PROJEKT_WILK_H
#define PO_PROJEKT_WILK_H
#include "Zwierze.h"


class Wilk : public Zwierze {
public:
    Wilk(int sila, int inicjatywa, int PolozenieX, int PolozenieY, Swiat* swiat, char znak);
    void Rysuj() const override;
    bool CzyObronil(Organizm *napastnik) override;
};



#endif //PO_PROJEKT_WILK_H
