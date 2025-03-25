#ifndef ASSIGNMENT_1_LIST_H
#define ASSIGNMENT_1_LIST_H

#include <iostream>
#include "Guest.h"

using namespace std;

class List {
private:
    Guest* list = new Guest;
    int length = 0;
    int maxSize;

public:
    List();
    List(int size);

    Guest& operator= (Guest guest);
    Guest& operator[](int index);
    int size();
    void insert(Guest guest);
    void removeAt(int loc);
    int search(string name);
};


#endif //ASSIGNMENT_1_LIST_H
