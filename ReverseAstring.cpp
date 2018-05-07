
#include <iostream>
#include<string.h>

using namespace std;


int main(){
	char arr[]="Manoj";
	char *str=arr;
	cout<<str<<endl;

	int len=sizeof(arr)/sizeof(arr[0])-1;
	cout << "string len is "<<len<<endl;
	char *begin=str;
	char *end= &arr[len-1];
	
	while(begin<end){
		char temp;
		temp = *begin;
		*begin++=*end;
		*end--=temp;
	}

	cout <<"Now String is "<<arr<<endl;

}