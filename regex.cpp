//Authors: Seamus Sommers and Joseph Racca
#include <iostream>
#include <regex>
#include <string>

using namespace std;

//Regex format: regex b("(Geek)(.*)");

int main() {

    string name;
    regex nombre("([a-zA-Z])*/s([a-zA-Z])*/s([a-zA-Z])*");
    string address;
    regex house("[a-zA-Z0-9 ]{3,20}(-|,)[a-zA-Z ]{3,50}(-|,)(|([#0-9a-zA-Z ]{3,50}(-|,)))[a-zA-Z ]{3,50}(-|,)[ 0-9]{5}");
    string BirthDate("");
    regex bday("[/d]{4}(/s|-)((1[0-2])|(0[1-9]))(/s|-)((0[0-9])|(1[0-9])|(2[0-9])|(3[0-1]))");
    string SSN;
    regex tracker("[0-9]{3}(-| )[0-9]{2}(-| )[0-9]{4}");
    string FoneNum;
    regex phone("^[0-9]{3}-[0-9]{3}-[0-9]{4}$");
    string CardNum;
    regex money("[/d]{4}(/s|-)?[/d]{4}(/s|-)?[/d]{4}(/s|-)?[/d]{3}(/s|-)?[/d]?");
    do  {
        cout << "put in your first, middle, and last name" << endl;
        cin >> name;
        if(regex_match(name, nombre)) {
            cout << "Incorrect format. Try again"<<endl;
        }
    } while(regex_match(name, nombre));
    do {
        cout << "put in your street address" << endl;
        cin >> address;
        if(regex_match(address, house)) {
            cout << "Incorrect format. Try again"<<endl;
        }
    } while(regex_match(address, house));
    do {
        cout << "put in your date of birth" << endl;
        cin >> BirthDate;
        if(regex_match(BirthDate, bday)) {
            cout << "Incorrect format. Try again"<<endl;
        }
    } while(regex_match(BirthDate, bday));
    do {
        cout << "put in your SSN" << endl;
        cin >> SSN;
        if(regex_match(SSN, tracker)) {
            cout << "Incorrect format. Try again"<<endl;
        }
    } while(regex_match(SSN, tracker));
    do  {
        cout << "put in your phone number" << endl;
        cin >> FoneNum;
        if(regex_match(FoneNum, phone)) {
            cout << "Incorrect format. Try again"<<endl;
        }
    } while(regex_match(FoneNum, phone));
    do {
        cout << "put in your credit card number" << endl;
        cin >> CardNum;
        if(regex_match(CardNum, money)) {
            cout << "Incorrect format. Try again"<<endl;
        }
    } while(regex_match(CardNum, money));

    return 0;
}