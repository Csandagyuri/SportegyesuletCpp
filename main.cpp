
#include "fajl.h"

using std::cout;
using std::endl;
using std::cin;
int main(){


    Menu c;
    String menu[] = {"Csapatok listazasa",  //1
    "Csapat tulajdonsagai",                 //2
    "Csapat hozzaad",                       //3
    "Edzo beallitasa",                      //4
    "Csapat tamogatasa",                    //5
    "Csapat pompomlany szamanak beallitasa",//6
    "Jatekos felvetele",                    //7
    "Kilepes es mentes"};                   //8

    int bemenet = -1;
    bool kilepes = false;
    while ( !kilepes ){
        cout << endl << "Sportegyesulet" << endl << endl;
        cout << "Valassza ki a kivant menupontot!"<< endl;
        cout << "(a menupont szamanak megadasaval)"<< endl;
        for(int i = 0; i < 8; i++){
            cout << i+1 << " -"<<menu[i] << endl<<endl;
        }
        cin >> bemenet;
        //cin>> szambemenet;
        String megadott;
        String megadott2;
        switch (bemenet) {
            case 1:
                c.csapatok_listazasa();
                break;
            case 2:
                c.listazas();
                break;
            case 3:
                c.csapat_felvetel();
                break;
            case 4:
                c.edzo();
                break;
            case 5:
                c.csapat_tamogatas();
                break;
            case 6:
                c.pompomlany_db();
            case 7:
                c.uj_jatekos();
            case 8:
                tarolobol_fajlba(c.get_eleje());
                kilepes = true;
                break;
            default:
                cout<< "!!!Nem megfelelo karakter kerult megadasra!!!" << endl;
                break;
        }
    }

    return 0;
}
