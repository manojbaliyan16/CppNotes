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
	Test():i(0){}
	Test(int value):i(value){}
	Test(const Test &other){
		i=other.i;
	}
	Test& operator=(const Test & obj){
		i=obj.i;
		return *this;

	}
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
	/*Test obj1, obj2;
	obj1.display();
	obj2.display();
	obj1=obj2++;
	obj1.display();
	obj2.display();
*/
	Test obj1(20);
	Test obj2(30);
	obj1=obj2++;
	obj1.display();
	obj2.display();

}

