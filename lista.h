#include <iostream>

template <typename T>
class Lista{
    struct ListaElem{
        ListaElem* kov;
        T adat;
    };

    ListaElem* eleje = NULL;

public:
    class iterator{

        ListaElem* elem;

    public:
        iterator(ListaElem* elem = NULL)
        :elem(elem){
        }

        iterator& operator++() {
            if(elem != NULL)
                elem = elem->kov;
            return *this;
        }

        iterator operator++(int) {
            iterator masolat = *this;
            ++(*this);
            return masolat;
        }

        T& operator*() const{
            return elem->adat;
        }



        bool operator==( iterator rhs) const{
            return elem == rhs.elem;
        }

        bool operator!=( iterator rhs) const{
            return elem != rhs.elem;
        }

        T* operator->() const{
            return &(elem->adat);
        }


    };

    iterator begin(){
        return iterator(eleje);
    }
    iterator end(){
        return iterator(NULL);
    }

    void hozzaad(const T& elem){                //Hozzáadja a lista legelejére!!
        ListaElem* uj = new ListaElem();
        uj->adat = elem;
        uj->kov = eleje;
        eleje = uj;
    }

    bool torol (const T& elem);                //A megadott elemet kitörli, ha van olyan, sikeres törlés esetén true-val tér vissza

    ~Lista(){
        if (eleje != NULL){
            ListaElem* lemarado = NULL;
            ListaElem* it = eleje;
            while (it!= NULL){
                lemarado = it;
                it = it->kov;
                delete lemarado;
            }
        }
    }

    bool eleme_e( const T&elem){
        ListaElem*it = eleje;
        while (it != NULL)
            if (it->adat == elem) return true;
        return false;
    }

};

