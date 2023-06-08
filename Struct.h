//
// Created by serj on 09.05.2023.
//

#ifndef C___STRUCT_H
#define C___STRUCT_H
#include <iostream>
#include <string>

using namespace std;

struct Contact{
    string name;
    string surname;
    string address;
    string email;
    string company;
    string birthdate;
    Contact(){};
    Contact(string a,string b,string c,string d,string e,string f);
    Contact(const Contact& other);
    Contact& operator = (Contact&& other);

    void Print();
};


#endif //C___STRUCT_H
