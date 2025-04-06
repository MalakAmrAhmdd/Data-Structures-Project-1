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

int main(){
    while (true){
        cout << "Enter Number of items to sort:";
        int m; cin >> m;
        cout << '\n';
        string type[m];
        for (auto i = 0; i < m; i++) {
            cout << "Enter data " << i+1 << ":";
            cin >> type[i];
        }
        if (isInteger(type[0])) {
            int arr[m];
            for (int i = 0; i < m; i++) {
                arr[i] = stoi(type[i]);
            }
            menu<int>(arr,m);
            break;
        }
        if (isFloat(type[0])) {
            double arr[m];
            for (int i = 0; i < m; i++) {
                arr[i] = stod(type[i]);
            }
            //menu<double>(arr,m);
            break;
        }
        //menu<string>(type,m);
        cout << "Do you want to sort another dataset? (y/n):";
        char repeat;
        cin >> repeat;
        if(repeat == 'n') {
            cout << "Thank you for using the sorting system! Goodbye!";
            break;
        }
    }
}
