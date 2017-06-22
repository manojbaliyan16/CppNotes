/*
 * BST.cpp
 *
 *  Created on: 05-Jun-2017
 *      Author: baliyan
 */
#include <stdio.h>
#include <stdlib.h>


#include <stdio.h>
int  BinarySearch(int* arr, int first, int last, int key){
	int mid=(first+last)/2;
	if(first>last)
		return 0;
	if(arr[mid]<key)
	BinarySearch(arr,mid+1,last,key);
	else if(arr[mid]==key)
	{
		return (mid+1);
	}
	else
		BinarySearch(arr,first,mid-1,key);

}
int BInarySearchItr(int* array,int first,int last, int search)
{
	int middle = (first+last)/2;

	   while (first <= last) {
	      if (array[middle] < search){
	         first = middle + 1;
	      }
	      else if (array[middle] == search) {
	    	  return middle+1;
	         break;
	      }
	      else
	      last = middle - 1;
	      middle = (first + last)/2;
	   }


}
int main()
{
   int c, first, last, middle, n, search, array[100];

   printf("Enter number of elements\n");
   scanf("%d",&n);

   printf("Enter %d integers\n", n);

   for (c = 0; c < n; c++)
      scanf("%d",&array[c]);

   printf("Enter value to find\n");
   scanf("%d", &search);

   first = 0;
   last = n - 1;
  int pos= BinarySearch(array,first,last,search);
  printf("%d found at location %d.\n", search, pos);
  printf("Search By Iterative method\n");
  int pos1=BInarySearchItr(array,first,last, search);
  printf("%d found at location %d.\n", search, pos1);

   return 0;
}
