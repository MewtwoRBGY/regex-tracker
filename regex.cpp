//Authors: Seamus Sommers and Joseph Racca
#include <iostream>
#include <regex>
#include <string>

using namespace std;

//Regex format: regex b("(Geek)(.*)");

bool Luhn(string card) {
    int sum = 0;
    bool alt = 0;
    for(int i = card.length() - 1; i >= 0; i--) {
        int x = card[i] - '0';
        if(alt) {
            x *=2;
            if(x > 9) {
            x = (x/10) + (x%10);
        }
        }
        alt = !alt;
        sum += x;
    }
    if((sum % 10) == 0) return true;
    else return false;
}

int main() {

    string name;
    regex nombre("([a-zA-Z])* ([a-zA-Z])* ([a-zA-Z])*");
    string address;
    regex house("[a-zA-Z0-9 ]{3,50}(-|,| )(|([#0-9a-zA-Z ]{3,50}(-|,| )))[a-zA-Z ]{3,50}(-|,| )[ 0-9]{5}");
    string BirthDate("");
    regex bday("[\\d]{4}(\\s|-)((1[0-2])|(0[1-9]))(\\s|-)((0[0-9])|(1[0-9])|(2[0-9])|(3[0-1]))");
    string SSN;
    regex tracker("[0-9]{3}(-| )[0-9]{2}(-| )[0-9]{4}");
    string FoneNum;
    regex phone("^\\(?[0-9]{3}\\)?(-| )?[0-9]{3}(-| )?[0-9]{4}$");
    string CardNum;
    regex money("(4\\d|5\\d|2\\d|34|37)[\\d]{2}[\\d]{4}[\\d]{4}[\\d]{3}[\\d]?"); // the numbers in the front make sure it is 4,5,2,34,37 to make sure it is visa,mastercard, or amex
    bool cardCorrect;
    do  {
        cout << "put in your first middle and last name, seperated by spaces" << endl;
        getline(cin, name);
        if(!regex_match(name, nombre)) {
            cout << "Incorrect format. Try again"<<endl;
        }
        if (name.length()>100){ cout << "your input is over 100 characters, shorten it" <<endl; continue;}

    } while(!regex_match(name, nombre) && name.length()<=100);
    do {
        cout << "Input in your street address followed by city and zip, seperated with spaces or commas" << endl;
        getline(cin, address);
        if(!regex_match(address, house)) {
            cout << "Incorrect format. Try again"<<endl;
        }
        regex check1("^\\D.*");
        if(regex_match(address, check1)) { cout<<"Address must start with a number"<<endl; }

    } while(!regex_match(address, house));
    do {
        cout << "Put in your date of birth, YYYY-MM-DD" << endl;
       getline(cin, BirthDate);
        if(!regex_match(BirthDate, bday)) {
            cout << "Incorrect format. Try again"<<endl;
        }
        regex check2("[\\D]");
        if(regex_match(BirthDate, check2)) { cout<<"No letters in birthday"<<endl; }
        if(BirthDate.length() < 8) { cout<<"Year has too few characters"<<endl; }
    } while(!regex_match(BirthDate, bday));
    do {
        cout << "put in your SSN" << endl;
        getline(cin, SSN);
        if(!regex_match(SSN, tracker)) {
            cout << "Incorrect format. Try again"<<endl;
        }
        regex check3("[\\D]");
        if(regex_match(SSN, check3)) { cout<<"No letters in SSN"<<endl; }

    } while(!regex_match(SSN, tracker));
    do  {
        cout << "put in your phone number, with either spaces or dashes or one at all." << endl;
        getline(cin, FoneNum);
        if(!regex_match(FoneNum, phone)) {
            cout << "Incorrect format. Try again"<<endl;
        }
        regex check4("[\\D]");
        if(FoneNum.length()<10) { cout<<"Length is too short"<<endl; }
        if(regex_match(FoneNum, check4)) { cout<<"No letters in phone number"<<endl; }

    } while(!regex_match(FoneNum, phone));
    do {
        cout << "put in your credit card number. NO SPACES" << endl;
        getline(cin, CardNum);
        if(!regex_match(CardNum, money)) {
            cout << "Incorrect format. Try again"<<endl;
            if (CardNum.length()<15){ cout << "your input is under 15 characters. Too short" <<endl;}
            cardCorrect = false;
        }
        else {
            cardCorrect = Luhn(CardNum);
            if(!Luhn(CardNum)) {
                cout << "Fails an annoying credit card formula"<<endl;;
            }
        }
    } while(!cardCorrect);
    cout<<"Thank you for signing away your soul ;)"<<endl;
    return 0;
}