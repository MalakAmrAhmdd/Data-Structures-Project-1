#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val);
};

class SortedLinkedList {
private:
    Node* head;

public:
    SortedLinkedList();
    void insert(int value);
    void remove(int index);
    friend ostream& operator<<(ostream& os, const SortedLinkedList& list);
    int operator[](int index);
    ~SortedLinkedList();
};

#endif // SORTEDLINKEDLIST_H