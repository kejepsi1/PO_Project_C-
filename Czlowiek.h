#ifndef PO_PROJEKT_CZLOWIEK_H
#define PO_PROJEKT_CZLOWIEK_H
#include "Zwierze.h"

class Czlowiek : public Zwierze {
public:
    Czlowiek(int sila, int inicjatywa, int PolozenieX, int PolozenieY, Swiat* swiat);
    void Rysuj() const override;
    void Akcja() override;
    bool CzyObronil(Organizm *napastnik) override;
};



#endif //PO_PROJEKT_CZLOWIEK_H
