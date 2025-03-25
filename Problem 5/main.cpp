#include <bits/stdc++.h>
#include "StatCalc.h"

using namespace std;

int main() {
    int choice;
    cout << "Choose the type of data you want to input: \n"
            "1. Integer\n"
            "2. Float\n"
            "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        int size;
        cout << "Enter the number of elements: ";
        cin >> size;
        StatCalc<int> statCalc(size);
        statCalc.inputData();
        statCalc.statisticMenu();
    } else if (choice == 2) {
        int size;
        cout << "Enter the number of elements: ";
        cin >> size;
        StatCalc<double> statCalc(size);
        statCalc.inputData();
        statCalc.statisticMenu();
    } else {
        cout << "Invalid choice" << endl;
    }

    return 0;
}