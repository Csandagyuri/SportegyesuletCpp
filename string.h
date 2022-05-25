#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include <iostream>



class String{
    char* str;
    size_t size;

public:

    String(char ch);
    String(const char * szoveg = "");  //konstruktor
    String(const String &rhs);     //másoló konstruktor
    ~String (){ delete[] str; }    //destruktor

    size_t get_size(){ return size;}
    const char* c_str() const{ return str; }    //c-s stringet ad vissza

    String operator+( const String& rhs) const;   //hozzafuzes
    String operator+(char rhs_c) const { return *this + String(rhs_c);}     //istreamhez
    String& operator=( const String& rhs);   //ertekadas
    bool operator==( const String& rhs);   //egyenloseg ellenirzese
    bool operator!=( const String& rhs);
};
    std::ostream& operator<<( std::ostream& os, const String& rhs); //kiiratás
    std::istream& operator>>( std::istream& is, String& s0); //input

#endif // STRING_H_INCLUDED
