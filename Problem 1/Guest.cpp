#include <iostream>
#include "Guest.h"

using namespace std;

Guest::Guest() {

}

Guest::Guest(string name, string contact, string date) {
    this->name = name;
    this->contact = contact;
    this->iftar_date = date;
}

void Guest::display_guest() {
    cout << "Guest: " << this->name <<
            ", Contact: " << this->contact <<
            ", Iftar Date: " << this->iftar_date << endl;
}

void Guest::update_invitation(string new_date) {
    this->iftar_date = new_date;
}