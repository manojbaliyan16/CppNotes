/*
 * PostIncrementOverloading.cpp
 *
 *  Created on: 22-Jun-2017
 *      Author: baliyan
 */

#include <iostream>

class Test{
	int i;
public:
	Test():i(10){}
	Test operator++(int)
		{
			Test test;
			test.i=i++;
			return test;
		}
	void display()
	{
		std::cout<<"i ="<<i<<std::endl;
	}
};

int main()
{
	Test obj1, obj2;
	obj1.display();
	obj2.display();
	obj1=obj2++;
	obj1.display();
	obj2.display();


}

