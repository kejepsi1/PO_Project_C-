#ifndef PO_PROJEKT_MLECZ_H
#define PO_PROJEKT_MLECZ_H
#include "Roslina.h"


class Mlecz  : public Roslina{
public:
    Mlecz(int PolozenieX, int PolozenieY, Swiat* swiat);
    void Rysuj() const override;
    void Akcja() override;
    bool SprawdzajSasiadow(int x, int y);
    bool CzyObronil(Organizm *napastnik) override;
    bool CzyMoznaZdeptac(Organizm *napastnik) override;
};


#endif //PO_PROJEKT_MLECZ_H
