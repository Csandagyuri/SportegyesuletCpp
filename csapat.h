#ifndef CSAPAT_H_INCLUDED
#define CSAPAT_H_INCLUDED

#include "lista.h"
#include "string.h"

class Csapat{
    String csapatnev;
    size_t letszam;
    Lista<String> jatekosok;
    String sportag;
    String edzo;                    //A focicsapatnak csak az egyik edzõje tárolódik

public:
    Csapat( String csapatnev, String sportag)       //Csapatot üresen lehet csak létrehozni, alap létszám 0!
        : csapatnev( csapatnev)
        , sportag (sportag){
            letszam = 0;
    }

    virtual ~Csapat(){ }

    String getCsapatnev(){ return csapatnev;}        //Visszaadja a csapat nevét (str)

    String getSportag(){ return sportag;}            // Visszaadja a csapat sportágát (str)

    size_t get_Letszam(){ return letszam;}          //Visszaadja a csapat létszámát (size_t)

    String getEdzo(){ return edzo;}                 //Visszaadja a csapat edzoje nevet (str)
    void set_edzo(String nev){  edzo = nev;}        //A csapat edzojet allitja be a parameterkent adott stringgel

    Lista<String> jatekosok_eleje() { return jatekosok; }

    bool operator==( Csapat& rhs);
    void operator+( String nev);                    //A csapathoz hozzáad egy új játékost
    void jatekosok_kiirasa();                       // A csapatban lévő összes játékos kiírása
    virtual void adat_kiiras() = 0;                 //A csapathoz tartozó összes adatot kiírja
};

using namespace std;
class Foci: public Csapat{
    String masod_edzo;                              //A focicsapatnak 2 edzője is van
public:
    Foci( String csapatnev, String sportag = "Foci")
    :Csapat(csapatnev, sportag){}
    virtual ~Foci(){  }

    void set_edzo2( String adat){ masod_edzo = adat;}    //A csapat második edzojet allitja be a parameterkent adott stringgel
    String get_edzo2(){ return masod_edzo; }            //Visszaadja a csapat masodik edzojet

    virtual void adat_kiiras();
};

class Kosar: public Csapat{
    int pompomlany_db;
public:
    Kosar ( String csapatnev, String sportag = "Kosar")
    :Csapat(csapatnev, sportag){}
    virtual ~Kosar(){ }

    void set_pompomlanyok( int adat){ pompomlany_db = adat;}
    int get_pompomlanyok(){ return pompomlany_db;}

    virtual void adat_kiiras();
};

class Kezilabda: public Csapat{
    int tamogatas;
public:
    Kezilabda(  String csapatnev, String sportag = "Kezilabda")
    :Csapat(csapatnev, sportag){}
    virtual ~Kezilabda(){ }

    void set_tamogatas( int adat){ tamogatas = adat;}
    int get_tamogatas(){ return tamogatas;}

    virtual void adat_kiiras();
};

#endif // CSAPAT_H_INCLUDED
