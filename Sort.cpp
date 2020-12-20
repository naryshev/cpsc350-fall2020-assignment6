/*
   Daniel Naryshev
   2327209
   dnaryshev@chapman.edu

 */
#include "Sort.h"

using namespace std;

Sort::Sort(string file) {
    arraySize = -1;
    readFile(file);
}

Sort::~Sort() {
    delete[] quickSortArray;
    delete[] mergeSortArray;
    delete[] selectionSortArray;
    delete[] insertionSortArray;
    delete[] bubbleSortArray;
}

void Sort::Start(string file) {
    readFile(file);

    cout << "Quick Sort..." << endl;
    quickSort();
    cout << endl;

    cout << "Merge Sort..." << endl;
    mergeSort();
    cout << endl;

    cout << "Selection Sort..." << endl;
    selectionSort();
    cout << endl;

    cout << "Insertion Sort..." << endl;
    insertionSort();
    cout << endl;

    cout << "Bubble Sort..." << endl;
    bubbleSort();
    cout << endl;

    cout << "~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Complete!" << endl;
    cout << endl;

}

void Sort::quickSort() {
    clock_t start = clock();

    quickSortAlgo(quickSortArray, 0, arraySize - 1);

    //Timing
    clock_t end = clock();
    float duration = (float(end - start) / (CLOCKS_PER_SEC)) * 1000;
    cout << "Start time: " << start << endl;
    cout << "End time: " << end << endl;
    cout << "Duration time: " << duration << endl;
}

void Sort::mergeSort() {
    clock_t start = clock();

    mergeAlgo(mergeSortArray, 0, arraySize - 1);

    //Timing
    clock_t end = clock();
    float duration = (float(end - start) / (CLOCKS_PER_SEC)) * 1000;
    cout << "Start time: " << start << endl;
    cout << "End time: " << end << endl;
    cout << "Duration time: " << duration << endl;
}

void Sort::selectionSort() {
    clock_t start = clock();

    int min;
    for (int i = 0; i < arraySize; i++) {
        // Find index of smallest remaining element
        min = i;
        for (int j = i + 1; j < arraySize + 1; j++) {
            if (selectionSortArray[j] < selectionSortArray[min]) {
                min = j;
            }
        }
        // Swap
        double temp = selectionSortArray[min];
        selectionSortArray[min] = selectionSortArray[i];
        selectionSortArray[i] = temp;
    }
    //Timing
    clock_t end = clock();
    float duration = (float(end - start) / (CLOCKS_PER_SEC)) * 1000;
    cout << "Start time: " << start << endl;
    cout << "End time: " << end << endl;
    cout << "Duration time: " << duration << endl;
}

void Sort::insertionSort() {
    clock_t start = clock();

    for (int j = 1; j < arraySize; j++) {
        double temp = insertionSortArray[j];
        int k = j - 1;
        // Insert insertionSortArray[i] into sorted part
        // stop once insertionSortArray[i] in correct position
        while (k >= 0 && insertionSortArray[k] > temp) {
            insertionSortArray[k + 1] = insertionSortArray[k];
            k--;
        }
        insertionSortArray[k + 1] = temp;
    }
    //Timing
    clock_t end = clock();
    float duration = (float(end - start) / (CLOCKS_PER_SEC)) * 1000;
    cout << "Start time: " << start << endl;
    cout << "End time: " << end << endl;
    cout << "Duration time: " << duration << endl;
}

void Sort::bubbleSort() {
    clock_t start = clock();

    for (int i = 0; i < arraySize - 1; i++) {
        for (int j = 0; j < arraySize - i - 1; j++) {
            if (bubbleSortArray[j] > bubbleSortArray[j + 1]) {
                swap(bubbleSortArray[j], bubbleSortArray[j + 1]);
            }
        }
    }
    //Timing
    clock_t end = clock();
    float duration = (float(end - start) / (CLOCKS_PER_SEC)) * 1000;
    cout << "Start time: " << start << endl;
    cout << "End time: " << end << endl;
    cout << "Duration time: " << duration << endl;
}


void Sort::quickSortAlgo(double * array, int l, int r) {
    if (l < r) {
        int part = partition(array, l, r);
        quickSortAlgo(array, l, part - 1);
        quickSortAlgo(array, part + 1, r);
    }
}

int Sort::partition(double * array, int l, int r) {
    int pivot = array[r];
    // Pick middle element as pivot
    int p = (l - 1);
    for (int j = l; j <= r - 1; j++) {
        if (array[j] <= pivot) {
            p++;
            swap(array[p], array[j]);
        }
    }
    //swap
    swap(array[p + 1], array[r]);
    return (p + 1);
}

void Sort::merge(double * array, int l, int m, int r) {
    int leftsize = m - l + 1;  // Size of merged partition
    int rightsize = r - m;     // Position to insert merged number
    double left[leftsize];      // Position to insert merged number
    double right[rightsize];    // Position of elements in right partition
    for (int i = 0; i < leftsize; i++) { //left
        left[i] = array[l + i];
    }
    for (int j = 0; j < rightsize; j++) { //right
        right[j] = array[m + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = l;
    // Add smallest element from left or right partition to merged numbers
    while (i < leftsize && j < rightsize) {
        if (left[i] <= right[j]) {
            array[k] = left[i++];
        } else {
            array[k] = right[j++];
        }
        k++;
    }
    // If left partition is not empty, add remaining elements to merged numbers
    while (i < leftsize) {
        array[k++] = left[i++];
    }
    // If right partition is not empty, add remaining elements to merged numbers

    while (j < rightsize) {
        array[k++] = right[j++];
    }
}

void Sort::mergeAlgo(double * array, int l, int r) {
    if (l < r) {
        int m = (l + r - 1) / 2; // Find the midpoint in the partition

        // Recursively sort left and right partitions
        mergeAlgo(array, l, m);
        mergeAlgo(array, m + 1, r);
        // Merge left and right partition in sorted order
        merge(array, l, m, r);
    }
}

// File IO
void Sort::readFile(string file) {
    ifstream instream;
    instream.open(file);

    double curr;
    int count = 0;
    while (instream >> curr) {
        if (count == 0) {
            arraySize = curr;
            quickSortArray = new double[arraySize]; //create new quick sort array of arraySize
            mergeSortArray = new double[arraySize]; //create new merge sort array of arraySize
            selectionSortArray = new double[arraySize]; //create new selection sort array of arraySize
            insertionSortArray = new double[arraySize]; //create new insertion sort array of arraySize
            bubbleSortArray = new double[arraySize]; //create new bubble sort array of arraySize
        } else {
            if (count > arraySize) {
                break;
            } else {
                quickSortArray[count - 1] = curr;
                mergeSortArray[count - 1] = curr;
                selectionSortArray[count - 1] = curr;
                insertionSortArray[count - 1] = curr;
                bubbleSortArray[count - 1] = curr;
            }
        }
        count++;
    }
    instream.close();
}
