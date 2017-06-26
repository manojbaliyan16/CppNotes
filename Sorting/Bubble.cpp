/*
 * Bubble.cpp
 *
 *  Created on: 25-Jun-2017
 *      Author: baliyan
 */
#include <iostream>
#include <vector>
#include <algorithm> //swap
using namespace std;


void BubbleSort(vector<int>& values) {
	bool swapped;
	int i, j;
	for (i = 0; i < values.size() - 1; i++) {
		swapped = false;
		for (j = 0; j < values.size() - i - 1; j++) {
			if (values[j] > values[j + 1]) {
				swap(values[j], values[j + 1]);
				swapped = true;
			}
		}
		if (!swapped)
			break;

	}

}
void merge(vector<int>& value, size_t start, size_t end) {
	//cout<<"Enter Merge::"<<endl;
	size_t mid = (start + end) / 2;
	int index1 = start;
	int index2 = mid + 1;
	vector<int> tempVect(end - start + 1);
	int nextValue = 0;
	for (int i = start; i <= end; i++) {
		if (index1 > mid) {
			tempVect[nextValue++] = value[index2++];
		} else if (index2 > end) {
			tempVect[nextValue++] = value[index1++];

		} else if (value[index1] < value[index2]) {
			tempVect[nextValue++] = value[index1++];
		} else
			tempVect[nextValue++] = value[index2++];
	}
	for (index1 = 0; index1 < nextValue; index1++) {
		value[start++] = tempVect[index1];
	}

}
//Time Complexity Of Merge Sort is
void mergesort(vector<int>& value, size_t start, size_t end) {
	//cout<<"Enter mergeSort::"<<endl;
	if (start < end) {
		size_t mid = (start + end) / 2;
		mergesort(value, start, mid);
		mergesort(value, mid + 1, end);
		merge(value, start, end);
	}

}
int partion(vector<int>& values, int start, int end) {
	int pivot = values[start];
	int i = start;
	int j = end + 1;
	while (1) {
		do {
			i++;
		} while (values[i] <= pivot && i < j);
		do {
			j--;
		} while (values[j] > pivot);
		if (i >= j)
			break;
		swap(values[i], values[j]);

	}
	swap(values[start], values[j]);
	return j;

}
void quicksort(vector<int>& values, int start, int end) {
	int j;

	if (start < end) {
		// divide and conquer
		j = partion(values, start, end);
		quicksort(values, start, j - 1);
		quicksort(values, j + 1, end);
	}

}

int main() {

	cout << "Enter The Number of Element is to be Entered in to the array"
			<< endl;
	int n, integers;
	cin >> n;
	vector<int> values;
	values.reserve(n);
	cout << "Enter the Integers" << endl;
	for (int i = 0; i < n; i++) {
		cin >> integers;
		values.push_back(integers);
	}
	vector<int>::iterator itr;
	/*BubbleSort(values);

	 cout<<"Sorted Elements are:"<<endl;
	 for (itr = values.begin(); itr != values.end(); ++itr) {
	 cout << "  " << *itr;
	 }
	 values.clear();
	 cout<<endl;
	 ******************For MergeSort******************
	 cout << "Entry for merge Sort " << endl;
	 cout << "Enter The Number of Element is to be Entered in to the array"
	 << endl;
	 cin >> n;
	 values.reserve(n);
	 cout << "Enter the Integers" << endl;
	 for (int i = 0; i < n; i++) {
	 cin >> integers;
	 values.push_back(integers);
	 }
	 */int size = values.size();

	quicksort(values, 0, size - 1);

	cout << "Sorted Elements are:" << endl;
	for (itr = values.begin(); itr != values.end(); ++itr) {
		cout << " " << *itr;
	}
	cout << endl;
}

