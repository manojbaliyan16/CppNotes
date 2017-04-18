#include <iostream>
using namespace std;


class Base1{
public:
	~Base1(){
		cout<<"Base1 Destructor"<<endl;
	}
};
class Derived1:public Base1{
public:
	~Derived1(){
		cout<<"Derived1 Destructor"<<endl;	
	}
};
class Base2{
public:
	virtual ~Base2(){
		cout<<"Base1 Destructor"<<endl;
	}	
};

class Derived2:public Base2{
public:
	~Derived2(){
		cout<<"Derived2 Destructor"<<endl;	
	}
};
int main(){
	Base1* bp=new Derived1;
	delete bp;
	cout<<"ForBase2"<<endl;
	Base2* bp2=new Derived2;
	delete bp2;
}