#include <bits/stdc++.h>
#include "SortingSystem.h"
using namespace std;

bool isInteger(const string& str) {
    return regex_match(str, regex("[-+]?[0-9]+"));
}

bool isFloat(const string& str) {
    return regex_match(str, regex("[-+]?[0-9]*\\.?[0-9]+([eE][-+]?[0-9]+)?"));
}

template<typename T>
void menu(T arr[], int size) {
    SortingSystem<T> list(size);
    for (int i = 0; i < size; i++) {
        list[i] = arr[i];
    }
    list.showMenu();
}

void readFromFile(const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        return;
    }

    int size;
    string dataType;
    while (file >> size >> dataType) {
        if (dataType == "int") {
            int* arr = new int[size];
            for (int i = 0; i < size; i++) {
                file >> arr[i];
            }
            menu(arr, size);
            delete[] arr;
        } else if (dataType == "string") {
            string* arr = new string[size];
            for (int i = 0; i < size; i++) {
                file >> arr[i];
            }
            menu(arr, size);
            delete[] arr;
        } else if (dataType == "double") {
            double* arr = new double[size];
            for (int i = 0; i < size; i++) {
                file >> arr[i];
            }
            menu(arr, size);
            delete[] arr;
        }
    }

    file.close();
}

int main() {
    while (true) {
        cout << "Choose an option:\n1. Interactive Menu\n2. Read from Test Case File\nEnter your choice (1 or 2): ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            
            cout << "Enter Number of items to sort: ";
            int m;
            cin >> m;
            cout << '\n';
            string type[m];
            for (int i = 0; i < m; i++) {
                cout << "Enter data " << i + 1 << ": ";
                cin >> type[i];
            }
            if (isInteger(type[0])) {
                int arr[m];
                for (int i = 0; i < m; i++) {
                    arr[i] = stoi(type[i]);
                }
                menu(arr, m);
            } else if (isFloat(type[0])) {
                double arr[m];
                for (int i = 0; i < m; i++) {
                    arr[i] = stod(type[i]);
                }
                menu(arr, m);
            } else {
                menu(type, m);
            }
            
        } else if (choice == 2) {
            readFromFile("testCasesProb4.txt");
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }

        cout << "Do you want to sort another dataset? (y/n): ";
        char repeat;
        cin >> repeat;
        if (repeat == 'n') {
            cout << "Thank you for using the sorting system! Goodbye!";
            break;
        }
    }

    return 0;
}
