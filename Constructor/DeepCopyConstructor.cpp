/*
 * DeepCopyConstructor.cpp
 *
 *  Created on: 07-Jul-2017
 *      Author: baliyan
 */
#include <iostream>


using namespace std;



class DeepCopy{
private:
	int *x;
	int N;
public:

	DeepCopy():x(NULL){}
//Copy Constructor With Deep Copy
	DeepCopy(const DeepCopy& obj){
		cout<<"Copy Constructor Called"<<endl;
		this->N=obj.N;
		x=new int[this->N];
	}
	//Assignment Operator With Deep Copy
		DeepCopy& operator=(const DeepCopy& obj)
		{
			this->N=obj.N;
			x=new int[this->N];
			return *this;
		}
	void Allcate(int N)
	{
		this->N=N;
		x=new int[this->N];
	}
	int* GetX(){
		return x;
	}
	~DeepCopy(){
		delete[]x;
	}
};
int main(){

DeepCopy obj1;//No Problem Default Constructor
DeepCopy obj2=obj1; //Copy Constructor Called
;//paramaterize constructor Called
DeepCopy obj4;
obj4.Allcate(10);
int *x=obj4.GetX();
DeepCopy obj3=obj4;
cout<<"Value o X "<<*x<<endl;
obj4=obj3=obj1;//

}


