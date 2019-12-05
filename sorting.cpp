/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Assignment 6 - Sort*/

#include <iostream>

#include "sorting.h"
#include <vector>
using namespace std;


//BUBBLE SORT
void sorting::bubbleSort(double bubbleArray[], int size)
{
	//cout << "Bubble sort" << endl;
	for (int i = 0; i < size; ++i)
	{
		//cout << "1" << endl;
		double temp = 0;
		for (int j = 0; j < size -1; ++j)
		{
			//cout << "2" << endl;
			if (bubbleArray[j] > bubbleArray[j + 1])
			{
				//cout << "3" << endl;
				temp = bubbleArray[j + 1];
				bubbleArray[j + 1] = bubbleArray[j];
				bubbleArray[j] = temp;
			}
		}
	}
}

//function to print the arrays
void sorting::printArray(double* myArray, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << myArray[i] << endl;
	}
}

//SELECTION SORT
void sorting::selectionSort(double selectionArray[], int size)
{
	//cout << "Selection Sort" << endl;
	int i, j, minIndex;
	double temp;
	for (i = 0; i < size - 1; i++)
	{
		minIndex = i;
		for (j = i + 1; j < size; j++)
		{
			if (selectionArray[j] < selectionArray[minIndex])
				//cout << "if statement" << endl;
				minIndex = j;
			//swap function
		}
		if (minIndex != i)
		{
			//cout << "in swap" << endl;		
			temp = selectionArray[i];
			selectionArray[i] = selectionArray[minIndex];
			selectionArray[minIndex] = temp;
		}
	}
}

//INSERT SORT
void sorting::insertSort(double insertArray[], int size)
{
	//cout << "Insert sort" << endl;
	for (int j = 1; j < size; ++j)
	{
		double temp = insertArray[j];
		int k = j;
		while (k > 0 && insertArray[k - 1] >= temp)
		{
			insertArray[k] = insertArray[k - 1];
			--k;
		}
		insertArray[k] = temp;
	}
}

double sorting::partition(double quickArray[], int min, int max)
{
	double pivot = quickArray[max];
	//the index of the smaller element
	int i = min - 1;

	for (int j = min; j <= max - 1; j++)
	{
		//if the current element (j) is less than the pivot
		if (quickArray[j] < pivot)
		{
			//increment the index of smaller element
			i++;
			//make it a double!
			//swap the values (im too lazy to make a swap function)	
			double temp = quickArray[i];
			quickArray[i] = quickArray[j];
			quickArray[j] = temp;
		}
	}

	//second swap thingy
	double temp = quickArray[i + 1];
	quickArray[i + 1] = quickArray[max];
	quickArray[max] = temp;
	//return the element
	return (i + 1);
}

//QUICK SORT
void sorting::quickSort(double quickArray[], int min, int max)
{
	
	if (min >= max)
	{
		return;
	}

	double part = partition(quickArray, min, max);
	//recursion
	quickSort(quickArray, min, part - 1);
	quickSort(quickArray, part + 1, max);
}

void sorting::merge(double* mergeArray, int leftLength, int rightLength, int middle)
{
	int left = middle - leftLength + 1;
	int right = rightLength - middle;

	//make two temperory arrays (old guy at bar - make it a double) for the right and left variables
	double* leftArray = new double[left];
	double* rightArray = new double[right];
	
	//copy the data into the temporary arrays to later be merged back together
	for (int i = 0; i < left; ++i)
	{
		leftArray[i] = mergeArray[leftLength + i];
	}
	for (int j = 0; j < right; ++j)
	{
		rightArray[j] = mergeArray[middle + j + 1];
	}

	//make variables for...dun dun dun...THE MERGE
	//starting index of the first array
	int i = 0;
	//starting index of the second array
	int j = 0;
	//starting index of the merged array
	int k = leftLength;

	while (i < left && j < right)
	{
		if (leftArray[i] <= rightArray[j])
		{
			mergeArray[k] = leftArray[i];
			i++;
		}
		else
		{
			mergeArray[k] = rightArray[j];
			j++;
		}
		//incriment the index
		k++;
	}

	while (i < left)
	{
		mergeArray[k] = leftArray[i];
		i++;
		k++;
	}

	while (j < right)
	{
		mergeArray[k] = rightArray[j];
		j++;
		k++;
	}

	//failed attempt
	/*while (low <= middle && j <= high)
	{
		if (mergeArray[low] < mergeArray[j])
		{
			temp[index] = mergeArray[low];
			low++;
		}
		else
		{
			temp = mergeArray[j];
			j++;
		}
	}

	while (low <= middle)
	{
		temp = mergeArray[low];
		low++;
	}

	while (j <= high)
	{
		temp = mergeArray[j];
		j++;
	}

	for (int i = low; i <= high; i++)
	{
		mergeArray[i] = temp[i - low];
	}*/
}

void sorting::mergeSort(double mergeArray[], int leftLength, int rightLength)
{
	int middle;
	if (leftLength < rightLength)
	{
		middle = (leftLength + rightLength) / 2;
		//split the data
		//lower values
		mergeSort(mergeArray, leftLength, middle);
		//upper values
		mergeSort(mergeArray, middle + 1, rightLength);

		//merge the values to get the total sorted output
		merge(mergeArray, leftLength, rightLength, middle);
	}
}

//TIME FUNCTION (for microseconds or whateva)
uint64_t sorting::getCurrentTime()
{
	return std::chrono::duration_cast<std::chrono::microseconds>(m_clock.now().time_since_epoch()).count();
}


