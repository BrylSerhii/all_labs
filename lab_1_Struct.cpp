//
// Created by serj on 09.05.2023.
//

#include "Struct.h"

Contact :: Contact(string a,string b,string c,string d,string e,string f){
    this-> name = a;
    this-> surname= b;
    this-> address = c;
    this-> email = d;
    this-> company = e;
    this-> birthdate = f;
}

Contact& Contact:: operator =(Contact&& other){
    name = other.name;
    surname= other.surname;
    address = other.address;
    email = other.email;
    company = other.company;
    birthdate = other.birthdate;
}

Contact :: Contact(const Contact& other)
    {
        name = other.name;
        surname = other.surname;
        address = other.address;
        email = other.email;
        company = other.company;
        birthdate = other.birthdate;
    }

void Contact :: Print(){
    cout<<name<<"\t";
    cout<<surname<<"\t";
    cout<<address<<"\t";
    cout<<email<<"\t";
    cout<<company<<"\t";
    cout<<birthdate<<"\n";

}
