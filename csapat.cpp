#include "csapat.h"

void Csapat::jatekosok_kiirasa(){
    for( Lista<String>::iterator it = jatekosok.begin(); it != jatekosok.end(); it++){
    std::cout <<  " " <<*it;
    }
}

void Csapat::operator+( String nev){                    //A listához hozzáad egy új elemet
    jatekosok.hozzaad( nev);
    letszam++;
}

bool Csapat::operator==( Csapat& rhs){
    if ( this->csapatnev == rhs.getCsapatnev())
        return true;
    return false;
}

void Foci::adat_kiiras(){
    cout<< this->getCsapatnev() << " ("<< this->getSportag()<< ")"<< endl;
    cout<< "Edzok: "<< this->getEdzo()<< ", "<< masod_edzo<< endl;
    cout<< "Jatekosok: ";
    this->jatekosok_kiirasa();
}

void Kosar::adat_kiiras(){
    cout<< this->getCsapatnev() << " ("<< this->getSportag()<< ")"<< endl;
    cout<< "Edzo: "<< this->getEdzo()<< endl;
    cout<< "Pompomlanyok szama:" << this->get_pompomlanyok() << endl;
    cout<< "Jatekosok: ";
    this->jatekosok_kiirasa();
}

void Kezilabda::adat_kiiras(){
    cout<< this->getCsapatnev() << " ("<< this->getSportag()<< ")"<< endl;
    cout<< "Edzo: "<< this->getEdzo()<< endl;
    cout<< "Csapat tamogatasanak osszege:" << this->get_tamogatas() << endl;
    cout<< "Jatekosok: ";
    this->jatekosok_kiirasa();
}
