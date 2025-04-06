#ifndef ASSIGNMENT_1_IFTARMANAGER_H
#define ASSIGNMENT_1_IFTARMANAGER_H

#include <iostream>
#include <winsock2.h>
#include <iostream>
#include <iostream>
#include <curl/curl.h>


#include "Guest.h"
#include "List.h"
using namespace std;


class IftarManager {
private:
    List guest_list;

public:
    IftarManager();
    IftarManager(int size);
    void add_guest(Guest guest);
    void remove_guest(string name);
    void display_all_guests();
    void update_guest_invitation(string name, string new_date);
    void send_reminder(string date);
    void send_email(string name, string contact, string date);
    void sort_guest_list();

};


#endif //ASSIGNMENT_1_IFTARMANAGER_H
