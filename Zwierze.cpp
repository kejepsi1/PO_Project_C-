#include "Zwierze.h"

Zwierze::Zwierze(int sila, int inicjatywa, int PolozenieX, int PolozenieY, Swiat* swiat, char znak) :
Organizm(sila,inicjatywa,PolozenieX,PolozenieY, swiat, znak) {}

Zwierze::~Zwierze() = default;