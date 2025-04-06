#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class SortedLinkedList {
private:
    Node* head;
public:
    SortedLinkedList() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        if (!head || head->data >= value) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next && current->next->data < value) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    friend ostream& operator<<(ostream& os, const SortedLinkedList& list) {
        Node* current = list.head;
        while (current) {
            os << current->data << " ";
            current = current->next;
        }
        return os;
    }

    ~SortedLinkedList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    SortedLinkedList list;
    int choice;
    cout << "Choose input method:\n1. File\n2. Manual\nEnter choice: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        string filename;
        cout << "Enter the file name: ";
        getline(cin, filename);
        ifstream inputFile(filename);
        if (!inputFile) {
            cerr << "Error opening file: " << filename << endl;
            return 1;
        }

        int value;
        while (inputFile >> value) {
            list.insert(value);
        }
        inputFile.close();
    } else if (choice == 2) {
        int value;
        cout << "Enter numbers (type -1 to stop):" << endl;
        while (true) {
            cin >> value;
            if (value == -1) break;
            list.insert(value);
        }
    } else {
        cerr << "Invalid choice" << endl;
        return 1;
    }

    cout << list << endl;

    return 0;
}
