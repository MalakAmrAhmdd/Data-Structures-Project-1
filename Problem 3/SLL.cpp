#include <bits/stdc++.h>
#include "SLL.h"
using namespace std;

Node::Node(int val) : data(val), next(nullptr) {}

SortedLinkedList::SortedLinkedList() : head(nullptr) {}

void SortedLinkedList::insert(int value) {
    Node *newNode = new Node(value);
    if (head == nullptr || head->data >= value) {
        newNode->next = head;
        head = newNode;
    } else {
        Node *current = head;
        while (current->next != nullptr && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void SortedLinkedList::remove(int index) {
    if (head == nullptr || index < 0) return;
    if (index == 0) {
        Node *temp = head;
        head = head->next;
        delete temp;
    } else {
        Node *current = head;
        for (int i = 0; i < index - 1; i++) {
            if (current->next == nullptr) return;
            current = current->next;
        }
        if (current->next == nullptr) return;
        Node *temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

ostream& operator<<(ostream& os, const SortedLinkedList& list) {
    Node* current = list.head;
    os << "[";
    while (current) {
        os << current->data;
        if (current->next) os << ", ";
        current = current->next;
    }
    os << "]";
    return os;
}

int SortedLinkedList::operator[](int index) {
    if (index < 0) throw out_of_range("Index out of range");
    Node* current = head;
    for (int i = 0; i < index; i++) {
        if (current == nullptr) throw out_of_range("Index out of range");
        current = current->next;
    }
    if (current == nullptr) throw out_of_range("Index out of range");
    return current->data;
}

SortedLinkedList::~SortedLinkedList() {
    Node *current = head;
    while (current != nullptr) {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
}