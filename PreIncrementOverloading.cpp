/*
 * PreIncrementOverloading.cpp
 *
 *  Created on: 22-Jun-2017
 *      Author: baliyan
 */
#include <iostream>
using namespace std;
class Test{
	int i;
public:
	Test():i(0){}
	Test(int value):i(value){}
	Test(const Test &other){
		cout << "copy Constructor "<<endl;
		i=other.i;
	}
	Test& operator=(const Test &other){
		cout << " Assignemnt Operaor "<<endl;
		i=other.i;
		return *this;
	}
	Test& operator++()
		{
			cout << "PreIncrementOverloading"<<endl;
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
	/*Test obj1,obj2;
	obj1.display();
	obj2.display();
	obj2=++obj1;
	obj1.display();
	obj2.display();
	++obj1;
	obj1.display();*/
	Test obj1(10);
	Test obj2(20);
	Test obj3=obj2;
	obj1=obj2=obj3;
	++obj3;
	obj3.display();
	obj2.display();
	obj1.display();
	obj2=++obj3;
	obj3.display();
}


