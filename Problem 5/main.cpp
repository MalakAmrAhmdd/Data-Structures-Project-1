#include <bits/stdc++.h>
#include "StatCalc.h"

using namespace std;

int main() {

    int size;
    cout << "Enter the size of the array : ";
    cin >> size;
    StatCalc<int> statCalc(size);
    statCalc.inputData();
    statCalc.statisticMenu();



    return 0;
}
