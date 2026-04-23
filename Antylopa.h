#ifndef PO_PROJEKT_ANTYLOPA_H
#define PO_PROJEKT_ANTYLOPA_H
#include "Zwierze.h"

class Antylopa : public Zwierze {
protected:
    Organizm* Rozmnazaj(int x, int y) override;
public:
    Antylopa(int PolozenieX, int PolozenieY, Swiat* swiat);
    void Rysuj() const override;
    void Akcja() override;
    void Kolizja() override;
    bool CzyOdpycha(Organizm *napastnik) override;
};

#endif //PO_PROJEKT_ANTYLOPA_H
