#ifndef PO_PROJEKT_TRAWA_H
#define PO_PROJEKT_TRAWA_H
#include "Roslina.h"


class Trawa  : public Roslina{
public:
    Trawa(int sila, int inicjatywa, int PolozenieX, int PolozenieY, Swiat* swiat, char znak);
    void Rysuj() const override;

};



#endif //PO_PROJEKT_TRAWA_H
