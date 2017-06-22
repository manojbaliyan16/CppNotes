/*
 * ExplicitConversion.cpp
 *
 *  Created on: 21-Jun-2017
 *      Author: baliyan
 */

#include <iostream>


class ComplexNumber{
	int real,img;
public:
	ComplexNumber():real(0),img(0){}
	ComplexNumber(const ComplexNumber& c){
		real = c.real;
		img =  c.img;
	}
	explicit ComplexNumber(double r, double i=0.0)
	ComplexNumber(double r, double i=0.0)
	{
		real=r;
		img=i;
	}
	friend void display(ComplexNumber cx)
	{
		std::cout<<"Real Numer is ::"<<cx.real << " img Numbe is :: "<<cx.img<<std::endl;
	}
};

int main(){
ComplexNumber one(1);
ComplexNumber five=5;
display(one);
//display(five);
display(ComplexNumber(300));
}


