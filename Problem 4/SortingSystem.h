#ifndef SORTINGSYSTEM_H
#define SORTINGSYSTEM_H
#include "bits/stdc++.h"
using namespace std;

template<typename T>
class SortingSystem {
private:
    T* data;
    int size;
public:
    explicit SortingSystem(int n);
    ~SortingSystem();

    T& operator[](int index);

    void insertionSort();
    void selectionSort();
    void bubblesort();
    void shellSort();
    void merge(int left, int mid, int right);
    void mergeSort(int left, int right);
    void mergeSortHelper();
    void quickSort(int left, int right);
    void countSort();
    void radixSort();
    void bucketSort();


    int partition(int low, int high);
    void quickSortHelper();

    void displayData();

    void measureSortTime(void (SortingSystem::*sortFunc)());

    void measureSortTime();

    void showMenu();
};


template<typename T>
SortingSystem<T>::SortingSystem(int n) {
    this->size = n;
    data = new T[size];
}

template<typename T>
SortingSystem<T>::~SortingSystem() {
    delete[] data;
}

template<typename T>
T& SortingSystem<T>::operator[](int index) {
    if (index >= size) throw invalid_argument("index");
    return data[index];
}

template<typename T>
void SortingSystem<T>::insertionSort() {
    for (int i = 1, j; i < size; i++) {
        T current = data[i];
        for (j = i-1; j >= 0 && current < data[j]; j--) {
            data[j+1] = data[j];
        }
        data[j + 1] = current;
        cout << "Iteration " << i+1 << ": "; displayData();
        cout << '\n';
    }
    cout << "\nSorted Data: "; displayData();
}

template<typename T>
void SortingSystem<T>::selectionSort() {
    for (int i = 0; i < size; i++) {
        int indexOfSmallest = i;
        for (int j = i+1; j < size; j++) {
            if (data[j] < data[indexOfSmallest])
                indexOfSmallest = j;
        }
        swap(data[indexOfSmallest], data[i]);
        cout << "Iteration " << i+1 << ": "; displayData();
        cout << '\n';
    }
    cout << "\nSorted Data: "; displayData();
}

template<typename T>
void SortingSystem<T>::bubblesort() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size-1 - i; j++) {
            if (data[j] > data[j+1]) {
                swap(data[j], data[j+1]);
            }
        }
        cout << "Iteration " << i+1 << ": "; displayData();
        cout << '\n';
    }
    cout << "\nSorted Data: "; displayData();
}

//template <typename T>
//void ShellSort(){}

template <typename T>
void SortingSystem<T>::merge(int left , int middle , int right){
    int i = 0, j = 0 , k = left;
    int n1 = middle-left+1 , n2 = right - middle;
    T arrL[n1] , arrR[n2];
    for (int n = 0; n <n1 ; ++n) arrL[n] = data[n+left];
    for (int n = 0; n <n2 ; ++n) arrR[n] = data[n + middle + 1];
    while(i<n1 && j < n2){
        if(arrL[i] < arrR[j]){
            data[k] = arrL[i];
            i++;
        }else{
            data[k] = arrR[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        data[k] = arrL[i];
        k++;i++;
    }
    while(j < n2){
        data[k] = arrR[j];
        k++;j++;
    }
}

template <typename T>
void SortingSystem<T>::mergeSort(int left, int right){
    static int i = 0;
    int middle = (left+right)/2;

    if (left >= right) {
        //cout <<"\n";
        return;
    }
    mergeSort(left, middle);
    mergeSort( middle + 1,right);
    merge(left, middle, right);
    cout<<"Iteration "<< i++<<": ";displayData();
    cout<<"\n";
}
template <typename T>
void SortingSystem<T>::mergeSortHelper(){
    mergeSort(0,size-1);
    cout << "\nSorted Data: "; displayData();
    cout<<"\n";
}

template<typename T>
int SortingSystem<T>::partition(int low, int high) {
    T pivot = data[low];
    static int itera = 0;
    int i = low;
    for (int j = low + 1; j <= high ; j++) {
        if(data[j] < pivot){
            i++;
            swap(data[i], data[j]);
        }
    }
    swap(data[i],data[low]);
    cout << "Pivot: " << pivot << " -> [";
    for (int k = low; k < i; k++) {
        cout << data[k];
        if (k < i - 1) cout << ", ";
    }
    cout << "] " << pivot << " [";
    for (int k = i + 1; k <= high; k++) {
        cout << data[k];
        if (k < high) cout << ", ";
    }
    cout << "]\n";
    return i;
}
template<typename T>
void SortingSystem<T>::quickSort(int left, int right) {

    //static int i = 0;
    if(left >= right) return;
    int piv = partition(left,right);
    quickSort(left,piv-1);
    quickSort(piv+1,right);


}
template <typename T>
void SortingSystem<T>::quickSortHelper() {
    quickSort(0,size-1);
    cout << "\nSorted Data: "; displayData();
    cout<<"\n";
}

template<typename T>
void SortingSystem<T>::displayData() {
    cout << '[';
    for (int i = 0; i < size-1; i++) {
        cout << data[i] << ", ";
    }
    cout << data[size-1] << ']';
}

template<typename T>
void SortingSystem<T>::measureSortTime(void(SortingSystem::*sortFunc)()) {
    auto start = chrono::high_resolution_clock::now();

    (this->*sortFunc)();

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> time = end - start;
    cout << "\nSorting Time: " << fixed << setprecision(6) << time.count() << " seconds\n";
}



template<typename T>
void SortingSystem<T>::showMenu() {
    cout << "\nSelect Sorting Algorithm: \n"
            "1. Insertion Sort\n"
            "2. Selection Sort\n"
            "3. Bubble Sort\n"
            "4. Shell Sort\n"
            "5. Merge Sort\n"
            "6. Quick Sort\n"
            "7. Count Sort (Only for integers)\n"
            "8. Radix Sort (Only for integers)\n"
            "9. Bucket Sort\n"
            "Enter your choice (1-9):";
    int choice; cin >> choice;
    switch (choice) {
        case 1:
            cout << "Sorting using Insertion Sort...\n";
            cout << "Initial Data: "; displayData();
            cout << '\n';
            measureSortTime(&SortingSystem<T>::insertionSort);
            cout << '\n';
            break;
        case 2:
            cout << "Sorting using Selection Sort...\n";
            cout << "Initial Data: "; displayData();
            cout << '\n';
            measureSortTime(&SortingSystem<T>::selectionSort);
            cout << '\n';
            break;
        case 3:
            cout << "Sorting using Bubble Sort...\n";
            cout << "Initial Data: "; displayData();
            cout << '\n';
            measureSortTime(&SortingSystem<T>::bubblesort);
            cout << '\n';
            break;
            // case 4:
            //     cout << "Sorting using Shell Sort...\n";
            //     cout << "Initial Data: "; displayData();
            //     cout << '\n';
            //     measureSortTime(&SortingSystem<T>::shellSort);
            //     cout << '\n';
            //     break;
        case 5:
            cout << "Sorting using Merge Sort...\n";
            cout << "Initial Data: "; displayData();
            cout << '\n';
            measureSortTime(&SortingSystem<T>::mergeSortHelper);
            cout << '\n';
            break;
             case 6:
                 cout << "Sorting using Quick Sort...\n";
                 cout << "Initial Data: "; displayData();
                 cout << '\n';
                 measureSortTime(&SortingSystem<T>::quickSortHelper);
                 cout << '\n';
                 break;
            // case 7:
            //     cout << "Sorting using Count Sort...\n";
            //     cout << "Initial Data: "; displayData();
            //     cout << '\n';
            //     measureSortTime(&SortingSystem<T>::countSort);
            //     cout << '\n';
            //     break;
            // case 8:
            //     cout << "Sorting using Radix Sort...\n";
            //     cout << "Initial Data: "; displayData();
            //     cout << '\n';
            //     measureSortTime(&SortingSystem<T>::radixSort);
            //     cout << '\n';
            //     break;
            // case 9:
            //     cout << "Sorting using Bucket Sort...\n";
            //     cout << "Initial Data: "; displayData();
            //     cout << '\n';
            //     measureSortTime(&SortingSystem<T>::bucketSort);
            //     cout << '\n';
            //     break;
        default:
            break;
    }
}


#endif //SORTINGSYSTEM_H
