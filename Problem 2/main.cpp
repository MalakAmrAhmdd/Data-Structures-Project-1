#include <bits/stdc++.h>
using namespace std;

void displayPoly(const int* arr, int size, int degree) {
    string display = "";
    bool firstTerm = true;

    for (int i = size - 1; i >= 0; i--) {
        bool isNegative = false;

        if (!firstTerm && i != 0) {
            if (arr[i] == 0) continue;
            display += (arr[i] > 0) ? " + " : " - ";
        } else {
            if (i == 0) {
                if (arr[i] < 0) isNegative = true;
            }
            if (arr[i] < 0 && i != 0) display += "-";
            firstTerm = false;
        }

        int coef = abs(arr[i]);

        if (i == 0) {
            if (isNegative) display += (" = -" + to_string(coef));
            else display += (" = " + to_string(coef));
        } else if (i == 1) {
            if (coef == 0) continue;
            display += to_string(coef);
        } else {
            if (coef == 0) continue;
            if (degree != 1) {
                if (coef == 1) display += "x^" + to_string(degree);
                else display += to_string(coef) + "x^" + to_string(degree);
            } else {
                if (coef == 1) display += "x";
                else display += to_string(coef) + "x";
            }
        }

        degree--;
    }

    cout << display << "\n";
}

void sumPoly(const int* arr1, const int* arr2, int size1, int size2) {
    int maxSize = max(size1, size2);
    int* result = new int[maxSize]();

    for (int i = 0; i < size1; i++) result[i] += arr1[i];
    for (int i = 0; i < size2; i++) result[i] += arr2[i];

    displayPoly(result, maxSize, maxSize - 2);
    delete[] result;
}

void diffPoly(const int* arr1, const int* arr2, int size1, int size2) {
    int maxSize = max(size1, size2);
    int* result = new int[maxSize]();

    for (int i = 0; i < size2; i++) result[i] += arr2[i];
    for (int i = 0; i < size1; i++) result[i] -= arr1[i];

    displayPoly(result, maxSize, maxSize - 2);
    delete[] result;
}

int main() {
    ifstream infile("test_cases.txt");
    if (!infile) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    int numTestCases;
    infile >> numTestCases;

    for (int t = 0; t < numTestCases; t++) {
        int n, m;
        infile >> n;
        int* arr1 = new int[n + 2];
        for (int i = 0; i < n + 2; i++) infile >> arr1[i];

        infile >> m;
        int* arr2 = new int[m + 2];
        for (int i = 0; i < m + 2; i++) infile >> arr2[i];

        cout << "Test Case " << t + 1 << ":\n";
        cout << "First polynomial: ";
        displayPoly(arr1, n + 2, n);
        cout << "Second polynomial: ";
        displayPoly(arr2, m + 2, m);
        cout << "Sum of polynomials: ";
        sumPoly(arr1, arr2, n + 2, m + 2);
        cout << "Difference of polynomials: ";
        diffPoly(arr1, arr2, n + 2, m + 2);

        delete[] arr1;
        delete[] arr2;
    }

    infile.close();
    return 0;
}
