// Find out the max occurence of a single element in to array

#include <iostream>
#define SIZE 20
int max(int*, int, int);
int countNum=0;
int main(){
	int arr[SIZE];
	int n;
	int k;
	
	std::cout<<"Enter the Number of Element in to array"<<'\n';
	std::cin>>n;
	k=n;
	std::cout<<"Enter The Element"<<'\n';
	if(n<=SIZE){
	for(int i=0;i<n;++i){
		std::cin>>arr[i];
	}
	std::cout <<"Array Out Put"<<'\n';
	for (int i = 0; i < n; ++i)
	{
		std::cout<<" "<<arr[i];
	}
	std::cout<<'\n';
	}
	else{
		std::cout<<"Execced The Array Limit"<<'\n';
	}
	int MaxRepeat=max(arr,n,k);
	std::cout<<"MaxRepeat= "<<MaxRepeat<<'\n';
	
	return 0;
}

int max(int* arr, int n, int k)
{		
	for (int i = 0; i< n; i++)
        arr[arr[i]%k] += k;
 
    // Find index of the maximum repeating element
    int max = arr[0], result = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            result = i;
        }
    }
	


		return result;
}