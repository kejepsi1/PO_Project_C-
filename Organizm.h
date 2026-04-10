#ifndef PO_PROJEKT_ORGANIZM_H
#define PO_PROJEKT_ORGANIZM_H

class Swiat;

class Organizm {
protected:
    int sila;
    int inicjatywa;
    int PolozenieX;
    int PolozenieY;
    int StarePolozenieX;
    int StarePolozenieY;
    char znak;
    Swiat* swiat;
public:
    int wiek;
    Organizm(int sila, int inicjatywa, int PolozenieX, int PolozenieY, Swiat* swiat, char znak);
    virtual void Rysuj() const = 0;
    int GetSila() const;
    int GetInicjatywa() const;
    int GetPolozenieX() const;
    int GetPolozenieY() const;
    char GetZnak() const;
    int GetWiek() const;
    virtual void Akcja();
    virtual void Kolizja();
    virtual bool CzyObronil(Organizm* napastnik) = 0;
    virtual ~Organizm();
    virtual bool CzyOdpycha(Organizm* napastnik);
    virtual void Cofnij();
};



#endif
