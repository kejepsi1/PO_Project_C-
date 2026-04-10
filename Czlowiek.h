#ifndef PO_PROJEKT_CZLOWIEK_H
#define PO_PROJEKT_CZLOWIEK_H
#include "Zwierze.h"

class Czlowiek : public Zwierze {
public:
    Czlowiek(int sila, int inicjatywa, int PolozenieX, int PolozenieY, Swiat* swiat, char znak);
    void Rysuj() const override;
    void Akcja() override;
    void Kolizja() override;
    bool CzyObronil(Organizm *napastnik) override;
};



#endif //PO_PROJEKT_CZLOWIEK_H
