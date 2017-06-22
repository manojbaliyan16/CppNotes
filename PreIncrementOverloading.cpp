/*
 * PreIncrementOverloading.cpp
 *
 *  Created on: 22-Jun-2017
 *      Author: baliyan
 */
#include <iostream>

class Test{
	int i;
public:
	Test():i(10){}
	Test& operator++()
		{
		Test test;

		test.i=++i;
		return *this;

		}
	void display()
	{
		std::cout<<"Value of i ="<<i<<std::endl;
	}
};
int main()
{
	Test obj1,obj2;
	obj1.display();
	obj2.display();
	obj2=++obj1;
	obj1.display();
	obj2.display();
	++obj1;
	obj1.display();
}


