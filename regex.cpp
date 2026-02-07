//Authors: Seamus Sommers and Joseph Racca
#include <iostream>
#include <regex>
#include <string>

using namespace std;

//Regex format: regex b("(Geek)(.*)");

int main() {

    string name = "";
    regex nombre("([a-zA-Z])*/s([a-zA-Z])*/s([a-zA-Z])*");
    string address = "";
    regex house("");
    string BirthDate("");
    regex bday("[/d]{4}(/w|-)((1[0-2])|(0[1-9]))(/w|-)((0[0-9])|(1[0-9])|(2[0-9])|(3[0-1]))");
    string SSN = "";
    regex tracker("");
    string FoneNum = "";
    regex phone("^[0-9]{3}-[0-9]{3}-[0-9]{4}$");
    string CardNum = "";
    regex money("");
    while(regex_match(name, nombre)) {
        cout << "put in your first, middle, and last name" << endl;
        cin >> name;
    }
    while(regex_match(address, house)) {
        cout << "put in your street address" << endl;
        cin >> address;
    }
    while(regex_match(SSN, tracker)) {
        cout << "put in your SSN" << endl;
        cin >> SSN;
    }
    while(regex_match(FoneNum, phone)) {
        cout << "put in your phone number" << endl;
        cin >> FoneNum;
    }
    while(regex_match(CardNum, money)) {
        cout << "put in your credit card number" << endl;
        cin >> CardNum;
    }

    return 0;
}