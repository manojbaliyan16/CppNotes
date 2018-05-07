#include <iostream>
#include <algorithm>
#include <string>


using namespace std;



int main(){

	string str="Manoj Kumar";
	int len = str.length();
	char *begin=str;
	char *end=str[len-1];
	while(begin<end){
		char temp;
		temp=*begin;
		*begin++=*end;
		*end--=temp;

	}
	cout << str <<endl;
	reverse(str.begin(),str.end()); 
	cout << str << endl;

}
