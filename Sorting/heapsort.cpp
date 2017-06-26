/*
 * heapsort.cpp
 *
 *  Created on: 26-Jun-2017
 *      Author: baliyan
 */
/*
Reference : https://www.programiz.com/dsa/heap-sort
How to create Complete Binary Tree From an array(Unsorted):
1. Select First Element as Root node
2. Second Element as the left child of root
3. Third Element as the right child of the root // here level One complete
4. Insert the 4th Element as the left child of the root at level 2nd.
repeat till no element left in the array.
Relationship between array index and Tree Element
if the index of an element in the array is i then element at index 2i will be left child
and element at index 2i+1 will be right child
and parent of any index i is given by lower bound of (i-1)/2
******************************************
Heap Data Structure:
1. it is a complete Binary Tree
2. All the nodes in the tree follow the property that they are greater than their children, so largest element is at root it is called Max-heap
3. If All the nodes in the tree follow the property that they are smaller than their children, Soo Smallest Element will be at root and it is called
Min-heap.
***********************************************
*****************************Heapify a Tree*************************
Heapify means starting from the Complete Binary Tree it will give you Max heap tree or Min heap tree

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void heapify(vector<int>& arr, int size, int i){
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	//find the largest among root, left and right nodes
	if(l < size && arr[l] > arr[largest])
	{
		largest=l;
	}
	if(r < size && arr[r] > arr[largest]){
		largest=r;
	}
	//swap and Continue to heapify if root is not largest
	if(i!=largest)
	{
		swap(arr[i],arr[largest]);
		heapify(arr,size,largest);
	}
}
void heapsort(vector<int>& arr, int size){
	//build Max Heap
	for(int i=size/2-1;i>=0;i--){
		heapify(arr,size,i);
	}
	for(int i=size;i >= 0;i--){
		swap(arr[0],arr[i]);
		heapify(arr,i,0);
	}


}
void display(vector<int>& vect){
	vector<int>::iterator itr;
	cout<<"In Display"<<endl;
	for(itr=vect.begin();itr!=vect.end();++itr)
	{
		cout<<" "<< *itr;
	}
	cout<<endl;
}
int main(){
int n, integers;
	cout<<"Enter The Number of Integers In to array"<<endl;
	cin>>n;
	vector<int> vect;
	vect.reserve(n);
	cout<<"Enter The Integers"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>integers;
		vect.push_back(integers);
	}
	int size=vect.size();
	heapsort(vect,size-1);
	//print the array
	display(vect);

}


