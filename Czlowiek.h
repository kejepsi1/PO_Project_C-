#ifndef PO_PROJEKT_CZLOWIEK_H
#define PO_PROJEKT_CZLOWIEK_H
#include "Zwierze.h"

class Czlowiek : public Zwierze {
private:
    int czas_odnowienia = 0;
    int czas_trwania_umiejetnosci = 0;
public:
    Czlowiek(int sila, int inicjatywa, int PolozenieX, int PolozenieY, Swiat* swiat);
    void Rysuj() const override;
    void Akcja() override;
    bool CzyObronil(Organizm *napastnik) override;
    bool CzyDrapieznik() override;
    bool CzyOdpycha(Organizm *napastnik) override;
    std::string DoZapisu() override;
    void SetCzasOdnowienia(int czas);
    void SetCzasTrwaniaUmiejetnosci(int czas);
};



#endif //PO_PROJEKT_CZLOWIEK_H
