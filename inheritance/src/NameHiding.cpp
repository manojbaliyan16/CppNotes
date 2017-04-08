#include <iostream>
#include <string>

using namespace std;



class Base{
public:
	int f() const {
		cout << "Base::f()"<<endl;
		return 1;
	}
	int f(string) const {
		cout << "Base::f(s)"<<endl;
		return 1;
	}
	void g(){}
};
class Derived1:public Base{
public:
	void g() const{}
};
class Derived2 :public Base{
public:
	int f() const{
		cout<<"derived2::f()"<<endl;
		return 2;
	}
};
class Derived3: public Base{
public:
	void f() const{
		cout <<"Derived3::f()"<<endl;
	}
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
	Derived3 d3;
	Derived4 d4;
	x=d4.f(1);//Derived4::f()

}