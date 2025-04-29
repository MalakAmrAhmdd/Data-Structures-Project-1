#include <bits/stdc++.h>
#include<SLL.h>
using namespace std;



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
