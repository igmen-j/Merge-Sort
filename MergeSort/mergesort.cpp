/*
	Justin Igmen
	200364880
	CS 340

	Merge sort
	Credits: Lecture notes, Wikipedia, and https://www.geeksforgeeks.org/merge-sort/
*/


#include <iostream>
#include <fstream>

#define N 4

using namespace std;

void merge_sort(int array[], int first, int last);
void merge(int array[], int first, int midpoint, int last);
void insertion_sort(int array[], int first, int last);

int arrSize;

int main() {
	int array[100];
	ofstream fout("solution.txt");

	cout << "******************************" << endl;
	cout << "*                            *" << endl;
	cout << "*         Merge Sort         *" << endl;
	cout << "*                            *" << endl;
	cout << "******************************" << endl;

	fout << "******************************" << endl;
	fout << "*                            *" << endl;
	fout << "*         Merge Sort         *" << endl;
	fout << "*                            *" << endl;
	fout << "******************************" << endl;

	cout << "Enter size of the array: ";
	cin >> arrSize;
	cout << "Enter array values: " << endl;
	for (int i = 0; i < arrSize; i++) {
		cin >> array[i];
	}

	cout << endl << "Unsorted array from user: " << endl;
	fout << endl << "Unsorted array from user: " << endl;
	for (int i = 0; i < arrSize; i++) {
		fout << array[i] << " ";
		cout << array[i] << " ";
	}
	cout << endl;
	fout << endl;

	fout.close();

	merge_sort(array, 0, arrSize);


	fout.open("solution.txt", std::fstream::app);

	cout << endl << "Sorted array: " << endl;
	fout << endl << "Sorted array: " << endl;
	for (int i = 0; i < arrSize; i++) {
		fout << array[i] << " ";
		cout << array[i] << " ";
	}

	cout << endl << endl << "See \"solution.txt\" in the solution folder to see it running" << endl << endl << endl;

	fout.close();

	system("PAUSE");
}

void insertion_sort(int array[], int first, int last) {
	for (int i = first + 1; i < last; i++) {
		int key = array[i];

		int j = i - 1;
		while (j >= first && array[j] > key)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = key;
	}
}

void merge_sort(int array[], int first, int last) {

	ofstream fout;
	fout.open("solution.txt", std::fstream::app);

	if (last - first <= N) {
		insertion_sort(array, first, last);
		fout << endl << "After insertion sort: ";
		for (int i = 0; i < arrSize; i++) {
			if (i == first) {
				fout << "[" << array[i] << " ";
			}
			else if (i == last - 1) {
				fout << array[i] << "]" << " ";
			}
			else {
				fout << array[i] << " ";
			}
		}
		fout << endl;

	}
	else {
		int midpoint = first + ((last - first) / 2);

		merge_sort(array, first, midpoint);
		merge_sort(array, midpoint, last);
		merge(array, first, midpoint, last);
		fout << endl << "After merging: ";
		for (int i = 0; i < arrSize; i++) {
			if (i == first) {
				fout << "[" << array[i] << " ";
			}
			else if (i == last - 1) {
				fout << array[i] << "]" << " ";
			}
			else {
				fout << array[i] << " ";
			}
		}
		fout << endl;
	}

	fout.close();
}

void merge(int array[], int first, int midpoint, int last) {
	int leftSize = midpoint - first;
	int rightSize = last - midpoint;

	int tempLeft[100];
	int tempRight[100];

	int i, j, k;

	//Temporary arrays for the two halves
	for (int i = 0; i < leftSize; i++)
		tempLeft[i] = array[first + i];
	for (int j = 0; j < rightSize; j++)
		tempRight[j] = array[midpoint + j];

	i = 0; 
	j = 0;
	k = first;


	int deletelater[100];

	int counter = 0;

	//Sort the two array into the main one
	while (i < leftSize && j < rightSize) {
		if (tempLeft[i] <= tempRight[j]) {
			array[k] = tempLeft[i];

			deletelater[counter] = tempLeft[i];

			i++;
		}
		else {
			array[k] = tempRight[j];

			deletelater[counter] = tempRight[j];

			j++;
		}
		counter++;
		k++;
	}

	//Put the remaing values into the main array
	while (i < leftSize) {
		array[k] = tempLeft[i];
		i++;
		k++;
	}
	while (j < rightSize) {
		array[k] = tempRight[j];
		j++;
		k++;
	}
}