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
            if (i==0) {
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
            }
            else {
                if (coef == 1) display += "x";
                else display += to_string(coef) + "x";
            }

        }

        degree --;
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

    displayPoly(result, maxSize , maxSize - 2);
    delete[] result;
}

int main() {
    cout << "Welcome to Polynomial program\n";

    // Test Case 1: Simple polynomials
        int arr1[] = {3, 1, 2, 3}; // 3x^2 + 2x + 1 = 3
        int arr2[] = {0, 4, 5, 6}; // 6x^2 + 5x + 4 = 0
        cout << "Test Case 1:\n";
        cout << "First polynomial: ";
        displayPoly(arr1, 4, 2);
        cout << "Second polynomial: ";
        displayPoly(arr2, 4, 2);
        cout << "Sum of polynomials: ";
        sumPoly(arr1, arr2, 4, 4);
        cout << "Difference of polynomials: ";
        diffPoly(arr1, arr2, 4, 4);


    // Test Case 2: Polynomials with different orders
        int arr3[] = {6, 1, 0, 3}; // 3x^2 + 1 = 6
        int arr4[] = {7, 4, 5};    // 5x + 4 = 7
        cout << "Test Case 2:\n";
        cout << "First polynomial: ";
        displayPoly(arr3, 4, 2);
        cout << "Second polynomial: ";
        displayPoly(arr4, 3, 1);
        cout << "Sum of polynomials: ";
        sumPoly(arr3, arr4, 4, 3);
        cout << "Difference of polynomials: ";
        diffPoly(arr3, arr4, 4, 3);


    // Test Case 3: Polynomials with negative coefficients
        int arr5[] = {-1, -1, -2, -3}; // -3x^2 - 2x - 1 = -1
        int arr6[] = {9, 4, -5, 6};   // 6x^2 - 5x + 4 = 9
        cout << "Test Case 3:\n";
        cout << "First polynomial: ";
        displayPoly(arr5, 4, 2);
        cout << "Second polynomial: ";
        displayPoly(arr6, 4, 2);
        cout << "Sum of polynomials: ";
        sumPoly(arr5, arr6, 4, 4);
        cout << "Difference of polynomials: ";
        diffPoly(arr5, arr6, 4, 4);


    // Test Case 4: Polynomials with zero coefficients
        int arr7[] = {0, 0, 0, 3}; // 3x^2 = 0
        int arr8[] = {4, 0, 0, 0}; // 4
        cout << "Test Case 4:\n";
        cout << "First polynomial: ";
        displayPoly(arr7, 4, 2);
        cout << "Second polynomial: ";
        displayPoly(arr8, 4, 0);
        cout << "Sum of polynomials: ";
        sumPoly(arr7, arr8, 4, 4);
        cout << "Difference of polynomials: ";
        diffPoly(arr7, arr8, 4, 4);


/* if you want to test the program interactively, uncomment the following code
    // First Polynomial
    cout << "Enter the order of the first polynomial: ";
    int n;
    cin >> n;
    cin.ignore();

    cout << "Enter the coefficients of the first polynomial (from right to left separated by space): ";
    string line1;
    getline(cin, line1);
    istringstream iss1(line1);
    int* arr1 = new int[n + 2];
    for (int i = 0; i < n+2; i++) iss1 >> arr1[i];

    // Second Polynomial
    cout << "Enter the order of the second polynomial: ";
    int m;
    cin >> m;
    cin.ignore();

    cout << "Enter the coefficients of the second polynomial (from right to left separated by space): ";
    string line2;
    getline(cin, line2);
    istringstream iss2(line2);
    int* arr2 = new int[m + 2];
    for (int i = 0; i < m+2; i++) iss2 >> arr2[i];

    // Display polynomials
    cout << "First polynomial: ";
    displayPoly(arr1, n + 2 , n);
    cout << "Second polynomial: ";
    displayPoly(arr2, m + 2 , m);

    // Sum and Difference
    cout << "Sum of polynomials: ";
    sumPoly(arr1, arr2, n + 2, m + 2);

    cout << "Difference of polynomials: ";
    diffPoly(arr1, arr2, n + 2, m + 2);

    // Free allocated memory
    delete[] arr1;
    delete[] arr2;
*/
    return 0;
}
