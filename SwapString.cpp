#include <iostream>
#include <string>
using namespace std;

void swapstring(string & str1, string & str2){
	string temp;
	temp=str1;
	str1=str2;
	str2=temp;
}

int main(int argc, char const *argv[])
{
	string str1="Manoj";
	string str2="Kumar";
	cout << "String is "<<endl;
	cout << str1<<" "<< str2 << endl;
	cout << "After Swap"<<endl;
	swapstring(str1, str2);
	cout << str1<<" "<< str2 << endl;
	return 0;
}
