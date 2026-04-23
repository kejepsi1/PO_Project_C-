#ifndef PO_PROJEKT_ORGANIZM_H
#define PO_PROJEKT_ORGANIZM_H
#include <string>

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
    int wiek;
    bool czyZyje = true;
    virtual Organizm* Rozmnazaj(int x,int y);
public:
    Organizm(int sila, int inicjatywa, int PolozenieX, int PolozenieY, Swiat* swiat, char znak);
    virtual void Rysuj() const = 0;
    int GetSila() const;
    int GetInicjatywa() const;
    int GetPolozenieX() const;
    int GetPolozenieY() const;
    char GetZnak() const;
    int GetWiek() const;
    void SetPolozenieX(int x);
    void SetPolozenieY(int y);
    void SetWiek(int x);
    void SetSila(int x);
    bool CzyZyje() const;
    void Zabij();
    virtual void Akcja();
    virtual void Kolizja();
    virtual bool CzyObronil(Organizm* napastnik);
    virtual ~Organizm();
    virtual bool CzyOdpycha(Organizm* napastnik);
    virtual void Cofnij();
    virtual void RozmnozSie();
    virtual bool CzyMoznaZdeptac(Organizm* napastnik);
    virtual bool CzyDrapieznik();
    virtual bool UniknijSmierci(Organizm* napastnik);
    virtual std::string DoZapisu();
};



#endif
