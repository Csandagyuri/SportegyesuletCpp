#include "lista.h"

template <typename T>

bool Lista<T>::torol(const T& elem){                                 //Kit�rli azt az elemet ami megegyezik a megadott param�terrel
        ListaElem* lemarado = NULL;                              //Ha t�bb van bel�le, csak 1x teszi ezt meg.
        for ( ListaElem* it = eleje; it != NULL; it = it->kov){
            if ( it->adat == elem){
                if ( lemarado == NULL) eleje = it->kov;
                else lemarado->kov = it->kov;
                delete it;
                return true;
            }
            lemarado = it;
        }
        std::cout << "Nem talalhato a megadott elem a listaban!" << std::endl << std::endl;      // Ha v�gigment sikeresen a ciklus, nincs benne.
        return false;
}

