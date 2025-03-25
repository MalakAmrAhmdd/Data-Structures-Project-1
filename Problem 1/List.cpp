#include "List.h"
#include <iostream>
using namespace std;

List::List() {
}

List::List(int len) {
    this->maxSize = len;
    list = new Guest[this->maxSize];
}

Guest& List::operator=(Guest guest) {
    delete[] list;
    list = &guest;
}

Guest& List::operator[](int index) {
    if (index >= 0 && index < length) {
        return list[index];
    } else {
        throw out_of_range("- Index out of range");
    }
}

int List::size() {
    return length;
}

void List::insert(Guest guest)  {
    if (maxSize > length) {
        list[length] = guest;
        this->length++;
    }
    else {
        cerr << "- Guest list is currently full!";
    }
}

void List::removeAt(int loc) {
    for (int i = loc; i < size() - 1; i++) {
        list[i] = list[i+1];
    }
    length--;
}

int List::search(string name) {
    for (int i = 0; i < this->size(); i++) {
        if (name == list[i].getName()) {
            return i;
        }
    }
    return -1;
}