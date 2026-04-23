#ifndef PO_PROJEKT_ROSLINA_H
#define PO_PROJEKT_ROSLINA_H
#include "Organizm.h"


class Roslina : public Organizm {
public:
    Roslina(int sila, int inicjatywa, int PolozenieX, int PolozenieY,Swiat* swiat, char znak);
    void Kolizja() override;
    virtual bool SprawdzajSasiadow(int x,int y);
    virtual ~Roslina();
};


#endif
