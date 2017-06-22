/*
 * reverseAword.cpp
 *
 *  Created on: 22-Jun-2017
 *      Author: baliyan
 */
#include <iostream>
#include <stdio.h>
#include <string.h>
void reverseS(char * start, char * end);
void reverseWord(char *s){
	char *wordbegin=s;
	char *temp=s;
	while(*temp)
	{
		temp++;
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

	reverseS(s,temp-1);
}
void reverseS(char * begin, char * end){
	char temp;
	while(begin<end){
		temp=*begin;
		*begin++=*end;
		*end--=temp;

	}
}

int main()
{
char s[]="It is my Country";
char *temp=s;
reverseWord(s);
std::cout<<s<<std::endl;
}



