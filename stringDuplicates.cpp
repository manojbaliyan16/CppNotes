#include <iostream>



using namespace std;
//Basic Program 
/*
int main(int argc, char const *argv[])
{
	char arr[]="aaabbbbccdddeffghi";
	int count =0;
	for(int i=0;arr[i]!='\0';i++){
		
		for(int j=i+1;arr[j]!='\0';j++){
			if(arr[i]==arr[j]){
				count++;
				cout << arr[i]<<" --->" << count << endl;
				break;
			}
		}
	}
	return 0;
}*/


// Changes the Logic 
const int NO_OF_CHAR=256;

void printDup(string s){
	int count[NO_OF_CHAR]={};
	for(int i=0;i<s.size();i++){
		cout<<"Value is "<< count[s[i]] << endl;
		count[s[i]]++;
		cout<<"Value is after Increment " << count[s[i]] << endl;
	}
	for(int i=0;i<s.size();i++){
		if(count[s[i]]>1){
			cout<< s[i] << " count = "<<count[s[i]]<<endl;
			count[s[i]]=0;

			}
	}


}
int main(int argc, char const *argv[])
{
	string s= "hello world";

	cout<<"Size is "<<s.size()<<endl;	
	printDup(s);


	return 0;
}