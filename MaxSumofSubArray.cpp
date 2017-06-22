/*
 * MaxSumofSubArray.cpp
 *
 *  Created on: 23-Jun-2017
 *      Author: baliyan
 */
#include <iostream>
#include <climits>
#include <stdio.h>
using namespace std;
int maxSumArray(int a[], int size) {
	int maxSoFar = INT_MIN;
	int maxEndinHere = 0;
	for (int i = 0; i < size; i++) {
		maxEndinHere = maxEndinHere + a[i];

		if (maxSoFar < maxEndinHere) {
			maxSoFar = maxEndinHere;
		}
		if (maxEndinHere < 0)
			maxEndinHere = 0;
	}
	return maxSoFar;
}

int main() {
int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
int size = sizeof(a) / sizeof(a[0]);
int maxSum = maxSumArray(a, size);
cout<<"max Sum is ::"<<maxSum<<endl;
}

