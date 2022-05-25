#include "csapat.h"

class Menu{
    Lista<Csapat*> csapatok;
public:
    Lista<Csapat*> get_eleje(){ return csapatok; }

    void csapat_felvetel();

// a listában szereplõ összes csapatot kiírja a kimenetre, és azok létszámát
    void csapatok_listazasa();

    void uj_jatekos();

    void edzo();

    void pompomlany_db();

    void csapat_tamogatas();

    void listazas ();

    Csapat* kereses( const String& csapat_nev);
};

void sortores();
void szunet();
