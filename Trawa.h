#ifndef PO_PROJEKT_TRAWA_H
#define PO_PROJEKT_TRAWA_H
#include "Roslina.h"


class Trawa  : public Roslina{
public:
    Trawa(int PolozenieX, int PolozenieY, Swiat* swiat, char znak);
    void Rysuj() const override;
    void Akcja() override;
    bool SprawdzajSasiadow(int x, int y);
    bool CzyObronil(Organizm *napastnik) override;


};



#endif //PO_PROJEKT_TRAWA_H
