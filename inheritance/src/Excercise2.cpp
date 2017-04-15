#include <iostream>
using namespace std;


class A{
	int i;
public:
	A(){
		cout<<"Constructor A::"<<"this=>>>"<<this<<endl;
	}
	~A(){
		cout<<"Destructor A::"<<"this=>>>"<<this<<endl;
	}
};
class B:public A{
	int i;
	public:
	B():A(){
		cout<<"Constructor B::"<<"this=>>>"<<this<<endl;
	}
	~B(){
		cout<<"Destructor B::"<<"this=>>>"<<this<<endl;
	}

};
class C: public B{
	//B b;
	public:
		C():B(){
		 	cout <<"Constructor C::"<<"this=>>>"<<this<<endl;
		 }
		~C(){
		cout<<"Destructor C::"<<"this=>>>"<<this<<endl;
	}

};
int main(){
	C c;
}
//Observation : With Out Creation of Constructor for c it is working fine 
