/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Assignment 6 - Sort*/

#include <iostream>
#include <chrono>
using namespace std;

class sorting 
{
public:
	//functions
	void bubbleSort(double bubbleArray[], int size);
	void printArray(double* myArray, int size);
	void selectionSort(double selectionArray[], int size);
	void insertSort(double insertArray[], int size);
	void quickSort(double quickArray[], int high, int low);
	double partition(double quickArray[], int high, int low);
	void merge(double* mergeArray, int leftLength, int rightLength, int middle);
	void mergeSort(double mergeArray[], int leftLength, int rightLength);
	uint64_t getCurrentTime();

	//variables
	std::chrono::high_resolution_clock m_clock;
};