/*
 * CopyConstructorUsage.cpp
 *
 *  Created on: 07-Jul-2017
 *      Author: baliyan
 */
#include <iostream>
#include <vector>

using namespace std;
class TestCopy
{
private:
	double length;
	double heiht;
	double breadth;
public:
	int objectcnt;
	int Cnt;

//constructor Definition
	TestCopy(){}
TestCopy(double l=2.0,double h=3.0,double b=4.0):length(l),heiht(h),breadth(b),Cnt(0),objectcnt(0){
	cout<<"Constructor Called"<<endl;
	objectcnt++;
	Cnt++;
}
//Copy Constructor

TestCopy(const TestCopy& obj){
	cout<<"I am In Copy Constructor"<<endl;
	length=obj.length;
	heiht=obj.heiht;
	breadth=obj.breadth;
	objectcnt=obj.objectcnt;
	Cnt=obj.Cnt;
}
~TestCopy(){

	cout<<"I am in TestCopy Destructor"<<endl;
}
int getCnt()
{
	return Cnt;
}
double volume(){
	return length*breadth*heiht;
}

};
int main(){
TestCopy obj1(10.0,20.0);
TestCopy obj2(obj1);//copy Constructor Called
cout<<"Volume is ::"<<obj2.volume()<<endl;
cout<<"object Count is "<<obj2.Cnt<<endl;

	return 0;
}







