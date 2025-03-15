
#ifndef ASSIGNMENT_1_STATCALC_H
#define ASSIGNMENT_1_STATCALC_H

#include <bits/stdc++.h>
using namespace std;
template <typename T>
class StatCalc {
private:
    T* data;
    int size;
public:
    StatCalc(int size);
    ~StatCalc();

    void sort(int arr[], int l , int m , int r);  // merge sort
    void mergesort(int arr[], int l, int r); // merge sort
    T findMedian();
    T findMin();
    T findMax();
    double findMean();
    T findSummation();

    void displayArray();
    void inputData();
    void statisticMenu();

};


#endif //ASSIGNMENT_1_STATCALC_H
