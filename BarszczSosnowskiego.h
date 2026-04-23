#ifndef PO_PROJEKT_BARSZCZSOSNOWSKIEGO_H
#define PO_PROJEKT_BARSZCZSOSNOWSKIEGO_H
#include "Roslina.h"


class BarszczSosnowskiego  : public Roslina{
protected:
    bool SprawdzajSasiadow(int x, int y) override;
public:
    BarszczSosnowskiego(int PolozenieX, int PolozenieY, Swiat* swiat);
    void Rysuj() const override;
    void Akcja() override;
    bool CzyObronil(Organizm *napastnik) override;
};

#endif //PO_PROJEKT_BARSZCZSOSNOWSKIEGO_H
