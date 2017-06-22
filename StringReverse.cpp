/*
 * StringReverse.cpp
 *
 *  Created on: 22-Jun-2017
 *      Author: baliyan
 */
#include <iostream>
#include <stdio.h>
#include <string.h>
static char str[]="Manoj is Searching";
int reverse(int pos)
{
	if(pos<(strlen(str)/2)){
		char ch;
		ch =str[pos];
		str[pos]=str[strlen(str)-pos-1];
		str[strlen(str)-pos-1]=ch;
		reverse(pos+1);
	}
}
int main()
{
	printf("original String is [%s]\n",str);
	reverse(0);
	printf("String after reverse is [%s]\n",str);


}



