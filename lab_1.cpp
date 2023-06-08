#include <iostream>
#include <string>
#include <vector>
#include "Struct.h"

using namespace std;
//імплементація інформаційної системи контактних даних з наступним інтерфейсом (інтерактивна взаємодія через консоль):
// створення/видалення ІС, додавання/видалення + (опціонально) редагування контакту
// (імʼя, прізвище, адреса, електронна адреса, компанія, день народження) виведення існуючих даних вихід з програми



int addContact(vector <Contact>& InfSys);
int deleteContact(vector<Contact>& InfSys);
int editContact(vector<Contact>& InfSys);
int showContacts(vector<Contact>&InfSys);

static int count=0;

int main(){
    vector <Contact> InfSys;
    while (true) {
        cout << "1. add Contact" << endl;
        cout << "2. delete Contact" << endl;
        cout << "3. edit Contact" << endl;
        cout << "4. show Contacts" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose option: ";

        int option;
        cin >> option;

        switch (option) {
            case 1:
                addContact(InfSys);
                break;
            case 2:
                deleteContact(InfSys);
                break;
            case 3:
                editContact(InfSys);
                break;
            case 4:
                showContacts(InfSys);
                break;
            case 5:
                return 0;
            default:
                cout << "Неправильна опція." << endl;
                break;
        }
    }
}

int addContact(vector<Contact>&InfSys){

    count++;
    cout<<"enter name"<<endl;
    string name;
    cin>>name;
    cout<<"enter surname"<<endl;
    string surname;
    cin>>surname;
    cout<<"enter address"<<endl;
    string address;
    cin>>address;
    cout<<"enter email"<<endl;
    string email;
    cin>>email;
    cout<<"enter company"<<endl;
    string company;
    cin>>company;
    cout<<"enter birthdate"<<endl;
    string birthdate;
    cin>>birthdate;
    Contact contact(name, surname, address, email, company, birthdate);
    InfSys.push_back(contact);
    cout<<"count "<<count<<endl;
    return 0;

}
int deleteContact(vector<Contact>& InfSys){
    vector<Contact>::iterator it;
    cout<<"Enter surname of contact to delete"<<endl;
    string surname;
    cin>>surname;
    for (it = InfSys.begin(); it != InfSys.end(); ++it) {
        if (it->surname == surname) {
            InfSys.erase(it);
            break;
        }
    }
    return 0;
}
int editContact(vector<Contact>& InfSys){
    vector<Contact>::iterator it;
    cout<<"Enter surname of contact to edit"<<endl;
    string surname;
    cin>>surname;
    for (it = InfSys.begin(); it != InfSys.end(); ++it){
        if(it->surname==surname){
            cout<<"Enter parameter to edit"<<endl;
            string parameter;
            cin>>parameter;
            if(parameter=="surname"){
                cout<<"Enter new surname for this contact"<<endl;
                string new_parameter;
                cin>>new_parameter;
                it->surname=new_parameter;
            }
            else if(parameter=="name"){
                cout<<"Enter new name for this contact"<<endl;
                string new_parameter;
                cin>>new_parameter;
                it->name=new_parameter;
            }
            else if(parameter=="address"){
                cout<<"Enter new address for this contact"<<endl;
                string new_parameter;
                cin>>new_parameter;
                it->address=new_parameter;
            }
            else if(parameter=="email"||parameter=="e-mail"){
                cout<<"Enter new email for this contact"<<endl;
                string new_parameter;
                cin>>new_parameter;
                it->email=new_parameter;
            }
            else if(parameter=="company"){
                cout<<"Enter new company for this contact"<<endl;
                string new_parameter;
                cin>>new_parameter;
                it->company=new_parameter;
            }
            else if(parameter=="birthdate"){
                cout<<"Enter new birthdate for this contact"<<endl;
                string new_parameter;
                cin>>new_parameter;
                it->birthdate=new_parameter;
            }
            cout << "Contact edited" << endl;
            return 1;
        }
    }
    cout << "Surname is not found"<<endl;
    return 0;
}

int showContacts(vector<Contact>& InfSys) {
    if (InfSys.empty()) {
        cout << "No contacts." << endl;
    } else {
        vector<Contact>::iterator it = InfSys.begin();
        cout << "Contacts:" << endl;
        for (; it != InfSys.end(); ++it) {
            it->Print();
            cout << endl;
        }
    }
    return 0;
}
