#include <iostream>
#include <cstring>

#include "string.h"

String::String(char ch) {
    size = 1;
    str = new char[size+1];
    str[0] = ch;
    str[1] = '\0';
}

String::String( const char* szoveg){
    size= strlen(szoveg);
    str= new char[ size+1];       // lezaro 0
    strcpy( str, szoveg);
}


String::String( const String& rhs){
    size= rhs.size;
    str= new char[ size+1];      //lezaro 0
    strcpy( str, rhs.str);
}


String String::operator+( const String& rhs) const{ //hozzafuzes
    String temp;
    temp.size= size+rhs.size;
    delete []temp.str;
    temp.str = new char[ temp.size+1];      //lezaro 0
    strcpy( temp.str, str);
    strcat( temp.str, rhs.str);
    return temp;
}


String& String::operator=( const String& rhs){   //ertekadas
    if ( this != &rhs){
        delete[] str;
        size = rhs.size;
        str = new char[ rhs.size+1];       //lezaro 0
        strcpy( str, rhs.str);
    }
    return *this;
}


bool String::operator==( const String& rhs){   //egyenloseg ellenorzese
    if ( size != rhs.size)
        return false;
    for( size_t i= 0; i< size; i++)
        if( str[ i]!= rhs.str[ i]) return false;
    return true;
}

bool String::operator!=( const String& rhs){
    return !(*this==rhs);
}



std::ostream& operator<<( std::ostream& os, const String& rhs){
    std::cout<< rhs.c_str();
    return os;
}

std::istream& operator>>( std::istream& is, String& s0) {
    unsigned char ch;
    s0 = String("");                            // üres string, ehhez fűzünk hozzá
	std::ios_base::fmtflags fl = is.flags(); // eltesszük a régi flag-eket
	is.setf(std::ios_base::skipws);			        // az elején eldobjuk a ws-t
    while (is >> ch) {
	    is.unsetf(std::ios_base::skipws);	        // utána pedig már nem
        if (isspace(ch)) {
            is.putback(ch);                 // na ezt nem kérjük
            break;
        } else {
            s0 = s0 + ch;                   // végére fűzzük a karaktert
        }
    }
	is.setf(fl);						    // visszaállítjuk a flag-eket
    return is;
}
