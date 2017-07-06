/*
 * stringR.cpp
 *
 *  Created on: 06-Jul-2017
 *      Author: baliyan
 */


#include <iostream>
#include <cstring>
using namespace std;
void reversestr(char *str)
{
	char *begin=&str[0];
	int len=strlen(str)-1;
	char *end=&str[len];

	while(begin<end){
		char temp;
		temp=*begin;

			*begin++=*end;
			*end--=temp;

		}
}

int main(){


	const char *temp1="Manoj";
	char *str=strdup(temp1);
	reversestr(str);
	cout<<str<<endl;



}





