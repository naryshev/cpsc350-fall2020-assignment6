/*
   Daniel Naryshev
   2327209
   dnaryshev@chapman.edu

 */
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
using namespace std;

class Sort{
	public:
		Sort(string file);
		~Sort();

		void Start(string file); //run the sorting

		void quickSort();
		void mergeSort();
		void selectionSort();
		void insertionSort();
		void bubbleSort();
	private:
		int arraySize;

		double* quickSortArray;
		double* mergeSortArray;
		double* selectionSortArray;
		double* insertionSortArray;
		double* bubbleSortArray;

		//quick sort functions
		void quickSortAlgo(double* array, int l, int r);
		int partition(double *array, int l, int r);

		//merge sort functions
		void mergeAlgo(double* array, int l, int r);
		void merge(double *array, int l, int m, int r);

		void readFile(string f); //File IO
};
