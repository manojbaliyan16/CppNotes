#include <iostream>
#include <string>

using namespace std;



class Base{
public:
	virtual int f() const {
		cout << "Base::f()"<<endl;
		return 1;
	}
	virtual int f(string) const {
		cout << "Base::f(s)"<<endl;
		return 1;
	}
	virtual void g(){}
};
class Derived1:public Base{
public:
	void g() const{}
};
class Derived2 :public Base{
public:
	//Overriding the Virtual Function
	int f() const{
		cout<<"derived2::f()"<<endl;
		return 2;
	}
};
class Derived3: public Base{
public:
	//can not change the return type
	/*
	void f() const{
		cout <<"Derived3::f()"<<endl;
	}
	*/
};
class Derived4:public Base{
public:
	int f(int) const{
		cout <<"Derived4::f()"<<endl;
	}
};
int main(){
	string s("hello");
	Derived1 d1;
	int x=d1.f();//"Base::f()"
	x=d1.f(s);
	Derived2 d2;
	x=d2.f();//derived2::f() 
	//!  d2.f(s); // string version hidden
  	Derived4 d4;
  	x = d4.f(1);
	//!  x = d4.f(); // f() version hidden
	//!  d4.f(s); // string version hidden
  	Base& br = d4; // Upcast
	//!  br.f(1); // Derived version unavailable
    br.f(); // Base version available
  	br.f(s); // Base version abailable

}
/*

if you override one of the overloaded member functions in the base class, the other overloaded versions
 become hidden in the derived class. In main( ) the code that tests Derived4 shows that this happens even 
 if the new version of f( ) isn’t actually overriding an existing virtual function interface – both of the base-class 
 versions of f( ) are hidden by f(int). However, if you upcast d4 to Base, then only the base-class versions are available 
 (because that’s what the base-class contract promises) and the derived-class version is not available (because it isn’t specified in the base class).
 */