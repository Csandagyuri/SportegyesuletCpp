#include "menu.h"
#include <conio.h>

Csapat* Menu::kereses( const String& csapat_nev){
    for ( Lista<Csapat*>::iterator it = csapatok.begin(); it != csapatok.end(); it++)
        if ((*it)-> getCsapatnev() == csapat_nev)
            return *it;
    return NULL;
}

void Menu::csapat_felvetel(){
    cout<< "Adja meg a hozzaadni kivant csapat nevet:" << endl;
    String megadott;
    cin>> megadott;
    if ( kereses(megadott) != NULL){
        cout<< "A megadott csapat mar szerepel az adatbazisban.";
        szunet();
        return;
    }
    cout<< "Adja meg a hozzaadni kivant csapat fajtajat ( foci / kezilabda / kosar ):" << endl;
    String megadott_fajta;
    cin>> megadott_fajta;
    if (megadott_fajta != "foci" && megadott_fajta != "kosar" && megadott_fajta != "kezilabda"){
        cout<< "Rossz csapat fajtat adtal meg!";
        szunet();
        return;
    }
    Csapat* uj;
    if (megadott_fajta == "foci")
        uj =new Foci(megadott, "foci");
    else if (megadott_fajta == "kosar")
        uj = new Kosar(megadott, "kosar");
    else if (megadott_fajta == "kezilabda")
        uj = new Kezilabda(megadott, "kezilabda");
    csapatok.hozzaad( uj);
    cout<< "Sikeresen hozzaadva az adatbazishoz!";
    szunet();
}


void Menu::csapatok_listazasa(){
    if ( csapatok.begin() == NULL)
        cout << "Nem talalhato az adatbazisban csapat";
    else
        for ( Lista<Csapat*>::iterator it = csapatok.begin(); it != csapatok.end(); it++){
            std::cout<< endl;
            std::cout << (*it)->getCsapatnev() <<"  " <<(*it)->get_Letszam() << "fo" << std::endl;
        }
    szunet();
}

void Menu::uj_jatekos(){
    cout<< "Adja meg a csapat nevet:" << endl;
    String megadott;
    cin>> megadott;
    Csapat* keresett = kereses(megadott);
    if ( keresett != NULL){
        cout<< "Adja meg az uj jatekos nevet:"<< endl;
        cin>> megadott;
        (*keresett)+megadott;
        cout<< "Sikeresen regisztralva!";
    }
    else cout<< "Nincs ilyen csapat a nyilvantartasban!";
    szunet();
}

void Menu::edzo(){
    cout<< "Adja meg a csapat nevet:";
    String megadott;
    cin>> megadott;
    Csapat* keresett = kereses(megadott);
    if ( keresett != NULL){
        cout<< "Adja meg az edzo nevet:"<< endl;
        cin>> megadott;
        keresett->set_edzo(megadott);
        if (keresett->getSportag() == "foci"){
            cout<< "Adja meg a masodik edzo nevet:"<< endl;
            cin>> megadott;
            Foci* foci_talalt = dynamic_cast<Foci*>(keresett);
            foci_talalt->set_edzo2(megadott);
        }
        cout<< "Sikeresen rogzitve.";
    }
    else cout<< "Nincs ilyen nevu csapat az adatbazisban";
    szunet();
}

void Menu::pompomlany_db(){
    cout<< "Adja meg a csapat nevet:";
    String megadott;
    cin>> megadott;
    Csapat* keresett = kereses(megadott);
    if ( keresett != NULL){
        if (keresett->getSportag() == "kosar"){
            cout<< "Adja meg a pompomlany csapat tagjainak szamat:"<< endl;
            unsigned int osszeg;
            cin>> osszeg;
            Kosar* kosar_talalt = dynamic_cast<Kosar*>(keresett);
            kosar_talalt->set_pompomlanyok(osszeg);
            cout<< "Sikeresen rogzitve.";
        }
        else cout<< "A megadott csapatnak nincs pompom csapata!"<<endl;
    }
    else cout<< "Nincs ilyen nevu csapat az adatbazisban";
    szunet();
}


void Menu::csapat_tamogatas(){
    cout<< "Adja meg a csapat nevet:";
    String megadott;
    cin>> megadott;
    Csapat* keresett = kereses(megadott);
    if ( keresett != NULL){
        if (keresett->getSportag() == "kezilabda"){
            cout<< "Adja meg a tamogatas osszeget:"<< endl;
            unsigned int osszeg;
            cin>> osszeg;
            Kezilabda* kezilabda_talalt = dynamic_cast<Kezilabda*>(keresett);
            kezilabda_talalt->set_tamogatas(osszeg);
            cout<< "Sikeresen rogzitve.";
        }
        else cout<< "A megadott csapatnak nem lehet tamogatast adni!"<<endl;
    }
    else cout<< "Nincs ilyen nevu csapat az adatbazisban";
    szunet();
}

void Menu::listazas (){
    std::cout << endl;
    bool talalt = false;
    String bemenet;
    cout<< "Adja meg a megtekinteni kivánt csapat nevet, figyeljen az betuk meretere, es az ekezetre is!" << endl;
    cin >> bemenet;
    for ( Lista<Csapat*>::iterator it = csapatok.begin(); it != csapatok.end(); it++)
        if ((*it)-> getCsapatnev() == bemenet){
            (*it)->adat_kiiras();
            talalt = true;
        }
    if (talalt == false)
        cout<< "Nincsen ilyen nevu csapat az adatbazisban";
    szunet();
}

 void sortores(){ std::cout << "- - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;
}

void szunet(){
    std::cout<< std::endl << "A folytatashoz nyomjon meg egy gombot!";
    getch();
    sortores();
}
