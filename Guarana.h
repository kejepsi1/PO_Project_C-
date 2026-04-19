#ifndef PO_PROJEKT_GUARANA_H
#define PO_PROJEKT_GUARANA_H
#include "Roslina.h"


class Guarana  : public Roslina{
public:
    Guarana(int PolozenieX, int PolozenieY, Swiat* swiat);
    void Rysuj() const override;
    void Akcja() override;
    bool SprawdzajSasiadow(int x, int y);
    bool CzyObronil(Organizm *napastnik) override;
    void Kolizja() override;
};



#endif //PO_PROJEKT_GUARANA_H
