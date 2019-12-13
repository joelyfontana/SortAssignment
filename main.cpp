/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Assignment 6 - Sort*/

#include <iostream>
#include "sorting.h"
#include <fstream>
#include <chrono>
#include <string>
using namespace std;
using namespace chrono;

int main(int argc, char** argv)
{
	//get the file name from the command prompt
	string fileName = argv[1];

	//error check to make sure that the use entered the file as a command line argument 
	if (argc != 2)
	{
		cout << "Please enter the input file name as a command line argument." << endl;
		return 0;
	}

	//open the file
	ifstream inputFile;
	inputFile.open(fileName);

	//read the file and put it the information into the array
	string line;
	getline(inputFile, line);
	//make the line representing size into an integer
	int size = stoi(line);
	cout << "size: " << size << endl;

	//make an array of doubles of the size (MAKE IT DYNAMIC)
	double* bubbleArray = new double[size];
	double* selectionArray = new double[size];
	double* insertArray = new double[size];
	double* quickArray = new double[size];
	double* mergeArray = new double[size];
	
	
	//put the contents of the file into the array
	for (int i = 0; i < size; i++)
	{
		getline(inputFile, line);
		bubbleArray[i] = stod(line);
		selectionArray[i] = stod(line);
		insertArray[i] = stod(line);
		quickArray[i] = stod(line);
		mergeArray[i] = stod(line);
	}

	//make a sorting object
	sorting sort;
	sorting time;

	//BUBBLE SORT
	cout << "\nBubble Sort" << endl;
	//get the time started and print it
	uint64_t currTime1 = time.getCurrentTime();
	//cout << "curr time: " << currTime << endl;
	auto time1 = chrono::system_clock::now();
	time_t bubbleStart = std::chrono::system_clock::to_time_t(time1);
	cout << "Time Started: " << ctime(&bubbleStart);

	//sort the array
	sort.bubbleSort(bubbleArray, size);
	//sort.printArray(bubbleArray, size);

	//get the time ended and print it
	uint64_t currTime2 = time.getCurrentTime();
	//cout << "curr time: " << currTime1 << endl;
	auto time2 = chrono::system_clock::now();
	time_t bubbleEnd = std::chrono::system_clock::to_time_t(time2);
	cout << "Total Time: " << currTime2 - currTime1 << " microseconds"<< endl;
	cout << "Time Ended: " << ctime(&bubbleEnd) <<"\n";
	

	//SELECTION SORT
	cout << "Selection Sort" << endl;
	uint64_t currTime3 = time.getCurrentTime();
	auto time3 = chrono::system_clock::now();
	time_t selectStart = std::chrono::system_clock::to_time_t(time3);
	cout << "Time Started: " << ctime(&selectStart);

	//sort the array
	sort.selectionSort(selectionArray, size);
	//sort.printArray(selectionArray, size);

	//get the time ended and print it
	uint64_t currTime4 = time.getCurrentTime();
	auto time4 = chrono::system_clock::now();
	time_t selectEnd = std::chrono::system_clock::to_time_t(time4);
	cout << "Total Time: " << currTime4 - currTime3 << " microseconds" << endl;
	cout << "Time Ended: " << ctime(&selectEnd)<<"\n";

	//INSERT SORT
	cout << "Insertion Sort" << endl;
	uint64_t currTime5 = time.getCurrentTime();
	auto time5 = chrono::system_clock::now();
	time_t insertStart = std::chrono::system_clock::to_time_t(time5);
	cout << "Time Started: " << ctime(&insertStart);

	//sort the array
	sort.insertSort(insertArray, size);
	//sort.printArray(insertArray, size);

	//get the time ended and print it
	uint64_t currTime6 = time.getCurrentTime();
	auto time6 = chrono::system_clock::now();
	time_t insertEnd = std::chrono::system_clock::to_time_t(time6);
	cout << "Total Time: " << currTime6 - currTime5 << " microseconds" << endl;
	cout << "Time Ended: " << ctime(&insertEnd)<<"\n";

	//QUICK SORT
	cout << "Quick Sort" << endl;
	uint64_t currTime7 = time.getCurrentTime();
	auto time7 = chrono::system_clock::now();
	time_t quickStart = std::chrono::system_clock::to_time_t(time7);
	cout << "Time Started: " << ctime(&quickStart);

	//sort the array
	sort.quickSort(quickArray, 0, size -1);
	//sort.printArray(quickArray, size);

	//get the time ended and print it
	uint64_t currTime8 = time.getCurrentTime();
	auto time8 = chrono::system_clock::now();
	time_t quickEnd = std::chrono::system_clock::to_time_t(time8);
	cout << "Total Time: " << currTime8 - currTime7 << " microseconds" << endl;
	cout << "Time Ended: " << ctime(&quickEnd)<<"\n";

	//MERGE SORT
	cout << "Merge Sort" << endl;
	uint64_t currTime9 = time.getCurrentTime();
	auto time9 = chrono::system_clock::now();
	time_t mergeStart = std::chrono::system_clock::to_time_t(time9);
	cout << "Time Started: " << ctime(&mergeStart);

	//sort the array
	sort.mergeSort(mergeArray, 0, size - 1);
	//sort.printArray(mergeArray, size);

	//get the time ended and print it
	uint64_t currTime10 = time.getCurrentTime();
	auto time10 = chrono::system_clock::now();
	time_t mergeEnd = std::chrono::system_clock::to_time_t(time10);
	cout << "Total Time: " << currTime10 - currTime9 << " microseconds" << endl;
	cout << "Time Ended: " << ctime(&mergeEnd) << "\n";
}
