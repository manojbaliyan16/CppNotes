// base-class handler can catch a derived-class exception:

#include <iostream>
using namespace std;

class X{
public:
	class Trouble{};
		class Big:public Trouble{};
		class Small:public Trouble{};
	void f(){throw (Big());}
};
int main(){
	X x;
	try{
		x.f();
	}
	catch(X::Trouble&){
		cout<<"caught Trouble\n";
	}
	catch(X::Small&){
		cout<<"caught Trouble X::Small\n";
	}
	catch(X::Big&){
		cout<<"caught Trouble X::Big\n";
	}
	
}

/*Here, the exception-handling mechanism will always match a Trouble object, or anything that is a Trouble (through public inheritance),[4]�to the first handler. That means the second and third handlers are never called because the 
first one captures them all. It makes more sense to catch the derived types first and put the base type at the end to catch 
anything less specific.
Notice that these examples catch exceptions by reference, although for these classes it isn�t important because
 there are no additional members in the derived classes, and there are no argument identifiers in the handlers anyway.
  You�ll usually want to use reference arguments rather than value arguments in your handlers to avoid slicing off information.*/