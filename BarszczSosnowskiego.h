#ifndef PO_PROJEKT_BARSZCZSOSNOWSKIEGO_H
#define PO_PROJEKT_BARSZCZSOSNOWSKIEGO_H
#include "Roslina.h"


class BarszczSosnowskiego  : public Roslina{
public:
    BarszczSosnowskiego(int PolozenieX, int PolozenieY, Swiat* swiat);
    void Rysuj() const override;
    void Akcja() override;
    bool SprawdzajSasiadow(int x, int y) override;
    bool CzyObronil(Organizm *napastnik) override;
};



#endif //PO_PROJEKT_BARSZCZSOSNOWSKIEGO_H
