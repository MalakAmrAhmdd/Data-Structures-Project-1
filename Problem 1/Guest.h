#ifndef ASSIGNMENT_1_GUEST_H
#define ASSIGNMENT_1_GUEST_H

#include <iostream>
using namespace std;

class Guest {
private:
    string name;
    string contact;
    string iftar_date;

public:
    Guest();
    Guest(string name, string contact, string date);

    string getName () {
        return name;
    }
    string getContact () {
        return contact;
    }
    string getDate () {
        return iftar_date;
    }

    void display_guest();
    void update_invitation(string new_date);
};


#endif //ASSIGNMENT_1_GUEST_H
