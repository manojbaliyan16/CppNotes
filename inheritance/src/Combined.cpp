//Inheritance and composition
#include <iostream>
using namespace std;


class A{
	int i;
public:
	A(int ii):i(ii){}
	~A(){}
	void f() const{}
};
class B{
int i;
public:
	B(int ii):i(ii){}
	~B(){}
	void f() const{}

};
class C:public B{
	A a;
public:
	C(int ii):B(ii), a(ii){}
	~C(){}
	void f() const{ //Redifination 
		a.f();
		B::f();
	}
};
/*
int main()
{
	cout << "going to Call derived Class Object"<<endl;
	C c(47);
}*/