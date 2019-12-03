/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Assignment 6 - Sort*/

#include <iostream>
using namespace std;

//BUBBLE SORT
void bubbleSort(int myArray[])
{
	cout << "Bubble sort" << endl;
	for (int i = 0; i < 10; ++i)
	{
		int temp = 0;
		for (int j = 0; j < 9; ++j)
		{
			if (myArray[j] > myArray[j + 1])
			{
				temp = myArray[j + 1];
				myArray[j + 1] = myArray[j];
				myArray[j] = temp;
			}
		}
	}
}

//function to print the arrays
void printArray(int myArray[])
{
	for (int i = 0; i < 10; ++i)
	{
		cout << myArray[i] << endl;
	}
}

//SELECTION SORT
void selectionSort(int myArray[], int n)
{
	cout << "Selection Sort" << endl;
	int i, j, minIndex, tmp;
	for (i = 0; i < n - 1; i++)
	{
		minIndex = 1;
		for (j = i + 1; j < n; j++)
		{
			if (myArray[j] < myArray[minIndex])
				minIndex = j;
			if (minIndex != i)
			{
				tmp = myArray[i];
				myArray[i] = myArray[minIndex];
				myArray[minIndex] = tmp;
			}
		}
	}
}

//INSERT SORT
void insertSort(double array2[])
{
	cout << "Insert sort" << endl;
	for (int j = 1; j < 10; ++j)
	{
		double temp = array2[j];
		int k = j;
		while (k > 0 && array2[k - 1] >= temp)
		{
			array2[] = array2[k - 1];
			--k;
		}
		array2[k] = temp;
	}
}

int main(int argc, char** argv)
{
	//declare the arrays
	int myArray[10] = { 3,2,5,6,4,1,10,14,12,66 };
	double array2[10] = { 3,2,5,6,4,1,10,14,12,66 };
	bubbleSort(myArray);
	printArray(myArray);
	selectionSort(myArray, 5);
}

