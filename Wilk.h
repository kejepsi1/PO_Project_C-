
#ifndef PO_PROJEKT_WILK_H
#define PO_PROJEKT_WILK_H
#include "Zwierze.h"


class Wilk : public Zwierze {
protected:
    Organizm* Rozmnazaj(int x, int y) override;
public:
    Wilk(int PolozenieX, int PolozenieY, Swiat* swiat);
    void Rysuj() const override;
    bool CzyDrapieznik() override;
};



#endif //PO_PROJEKT_WILK_H
