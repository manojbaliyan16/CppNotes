// Virtual calls inside destructors
#include <iostream>
using namespace std;

class Base{
public:
	virtual ~Base(){
		cout<<" Base \n";
		f();
	}
	virtual void f(){
		cout<<"Base::f()\n";
	}
};
class Derived:public Base{
	~Derived(){
		cout<<"Derived:Destructor\n";
	}
		void f(){
			cout <<"Derived:f()\n";
		}
};

int main(){
	Base* bp=new Derived;
	delete bp;
}/*
Derived:Destructor
Base 
Base::f()
Why is this? Suppose the virtual mechanism were used inside the destructor. Then it would be possible for the virtual call to resolve to a function that was “farther out” (more derived) on the inheritance hierarchy than the current destructor. But destructors are called from the “outside in” (from the most-derived destructor down to the base destructor), so the actual function called would rely on portions of an object that have already been destroyed! Instead, the compiler resolves the calls at compile-time and calls only the “local” version of the function. Notice that the same is true for the constructor (as described earlier), but in the constructor’s case the type
information wasn’t available, whereas in the destructor the information (that is, the VPTR) is there, but is isn’t reliable.
*/