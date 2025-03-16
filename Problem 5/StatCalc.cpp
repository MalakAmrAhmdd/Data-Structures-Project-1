#include <bits/stdc++.h>
using namespace std;
#include "StatCalc.h"

template <typename T>
StatCalc<T>::StatCalc(int size) {
    this->size = size;
    data = new T[size];
}

template <typename T>
StatCalc<T>::~StatCalc() {
    delete[] data;
}

template <typename T>
void StatCalc<T>::sort(int arr[], int l, int m, int r) {
    int i = 0, j = 0, k = l;
    int n1 = m - l + 1;
    int n2 = r - m;
    int arrL[n1];
    int arrR[n2];
    for (int n = 0; n < n1; ++n) {
        arrL[n] = arr[n + l];
    }
    for (int n = 0; n < n2; ++n) {
        arrR[n] = arr[n + m + 1];
    }
    while (i < n1 && j < n2) {
        if (arrL[i] < arrR[j]) {
            arr[k] = arrL[i];
            i++;
        } else {
            arr[k] = arrR[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = arrL[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = arrR[j];
        j++;
        k++;
    }
}

template <typename T>
void StatCalc<T>::mergesort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        sort(arr, l, m, r);
    }
}

template <typename T>
T StatCalc<T>::findMedian() {
    mergesort(data, 0, size - 1);
    if (size % 2 == 0) {
        return (data[size / 2 - 1] + data[size / 2]) / 2;
    } else {
        return data[size / 2];
    }
}

template <typename T>
T StatCalc<T>::findMin() {
    mergesort(data, 0, size - 1);
    return data[0];
}

template <typename T>
T StatCalc<T>::findMax() {
    mergesort(data, 0, size - 1);
    return data[size - 1];
}

template <typename T>
double StatCalc<T>::findMean() {
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += data[i];
    }
    return sum / size;
}

template <typename T>
T StatCalc<T>::findSummation() {
    T sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += data[i];
    }
    return sum;
}

template <typename T>
void StatCalc<T>::displayArray() {
    for (int i = 0; i < size; ++i) {
        cout << data[i] << " ";
    }
    cout <<"Data: " <<endl;
}

template <typename T>
void StatCalc<T>::inputData() {
    for (int i = 1; i <= size; ++i) {
        cout << "Enter element " << i <<": ";
        cin >> data[i-1];
    }
}

template <typename T>
void StatCalc<T>::statisticMenu() {
    int choice;
    do {
        cout << "1. Find Median" << endl;
        cout << "2. Find Min" << endl;
        cout << "3. Find Max" << endl;
        cout << "4. Find Mean" << endl;
        cout << "5. Find Summation" << endl;
        cout << "6. Display Array" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Median : " << findMedian() << endl;
                break;
            case 2:
                cout << "Min : " << findMin() << endl;
                break;
            case 3:
                cout << "Max : " << findMax() << endl;
                break;
            case 4:
                cout << "Mean : " << findMean() << endl;
                break;
            case 5:
                cout << "Summation : " << findSummation() << endl;
                break;
            case 6:
                displayArray();
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 7);
}

// Explicit instantiation of the template
template class StatCalc<int>;