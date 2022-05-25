#include "fajl.h"

void tarolobol_fajlba(Lista<Csapat*> mentendo){
    ofstream myfile;
    myfile.open ("sportegyesulet.txt");

    for (Lista<Csapat*>::iterator it = mentendo.begin(); it != mentendo.end(); it++){
        Csapat* keresett = kereses( (*it)->getCsapatnev);
        myfile<< keresett->getCsapatnev() << " " << keresett->getSportag() << " " << keresett->getEdzo() << " ";
        if (keresett->getSportag() == "foci"){
            Foci* castolt_talalt = dynamic_cast<Foci*>(keresett);
            myfile<< castolt_talalt->get_edzo2() << " ";
        }
        if (keresett->getSportag() == "kosar"){
            Kosar* castolt_talalt = dynamic_cast<Kosar*>(keresett);
            myfile<< castolt_talalt->get_pompomlanyok()<< " ";
        }
        else{
            Kezilabda* castolt_talalt = dynamic_cast<Kezilabda*>(keresett);
            myfile<< castolt_talalt->get_tamogatas()<< " ";
        }
        for (Lista<String>::iterator iter = (keresett.jatekosok_eleje()).begin(); iter != NULL; iter++){
            myfile<< (*iter) << " ";
        }

    }
    myfile.close();
}
