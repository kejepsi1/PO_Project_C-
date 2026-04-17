#ifndef PO_PROJEKT_ZWIERZE_H
#define PO_PROJEKT_ZWIERZE_H
#include "Organizm.h"


class Zwierze : public Organizm {
public:
    Zwierze(int sila, int inicjatywa, int PolozenieX, int PolozenieY, Swiat* swiat, char znak);
    virtual ~Zwierze();
    void RozmnozSie();
};



#endif
