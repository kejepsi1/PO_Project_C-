#ifndef PO_PROJEKT_WILCZEJAGODY_H
#define PO_PROJEKT_WILCZEJAGODY_H
#include "Roslina.h"


class WilczeJagody  : public Roslina{
public:
    WilczeJagody(int PolozenieX, int PolozenieY, Swiat* swiat);
    void Rysuj() const override;
    void Akcja() override;
    bool SprawdzajSasiadow(int x, int y);
    bool CzyObronil(Organizm *napastnik) override;
    void Kolizja() override;
};




#endif //PO_PROJEKT_WILCZEJAGODY_H
