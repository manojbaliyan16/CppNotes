/*
 * reverseAword.cpp
 *
 *  Created on: 22-Jun-2017
 *      Author: baliyan
 */
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
void reverseS(char * start, char * end);
void reverseWord(char *s){
	char *wordbegin=s;
	char *temp=s;
	while(*temp)
	{
		cout<<"char in temp -->"<<*temp<<endl;
		temp++;
		cout<<"char in temp++ -->"<<*temp<<endl;
		if(*temp=='\0')
		{
			reverseS(wordbegin,temp-1);
		}
		else if(*temp==' ')
		{
			reverseS(wordbegin,temp-1);
			wordbegin=temp+1;
		}
	}
	cout<<"Final String is -->"<<s<<endl;
	reverseS(s,temp-1);
}
void reverseS(char * begin, char * end){
	char temp;
	cout<<"char in begin -->"<<*begin<<endl;
	cout<<"char in end -->"<<*end<<endl;
	while(begin<end){
		temp=*begin;
		*begin++=*end;
		*end--=temp;

	}
	cout << "String in reverseS"<< begin<<endl;
}

int main()
{
char s[]="It is my  Country";
char *temp=s;
reverseWord(s);
std::cout<<s<<std::endl;
}



