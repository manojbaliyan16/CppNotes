#include <iostream>
using namespace std;

class Parent{
	int i;
public:
	Parent(int ii):i(ii){
	cout<<" Parent(int ii)::" << endl;
	}
	Parent(const Parent& b):i(b.i){
		cout<<"Parent: Copy Constructor::"<<endl;
	}
	Parent():i(0){
		cout << "Default Constructor::"<< endl; 
	}
	friend ostream& operator<<(ostream& os, const Parent& right){ // friend fucntion as we have to take two argument 
	return os << "Parent::" << right.i << endl;
	}
};

class Member{
	int i;
public:
	Member(int ii):i(ii){
		cout<<"Member(int ii)::" << endl;
	}
	Member(const Member& b):i(b.i){
		cout << "Member:Copy Constructor::"<< endl;
	}

	// Didn't take any default Constructor Here
	friend ostream& operator<<(ostream& os,const Member& m){
		return os << "Member& ::"<< m.i << endl;
	}
};
class Child : public Parent{
	int i;
  Member m; //composition
public:
	Child(int ii) : Parent(ii), i(ii), m(ii){
		cout << "child(int ii)"<<endl;
	}
	/*Child(const Child& c):Parent(c),i(c.i),m(c.i){
		cout<<"Child::Copy Constrtuctor Called:"<<endl;
	}
*/friend ostream& operator<<(ostream& os, const Child& c){
	return os << (Parent&)c << c.m << "Child:: " << c.i << endl; //child object c is casting in to parent, 
	//here we are doing upcasting means we are converting child object in to Parent Object,  
	}
};



int main(){
Child c(2);
cout << "Copy Constructor Called"<<endl;
Child c2=c;
cout << "Value is C2:\n "<< c2;
}
/* Output::
Parent(int ii):: //HERE c(2) created which is casting in to (Parent&)c so Paraent parameterized constructor called 
Member(int ii)::
child(int ii)
Copy Constructor Called
Parent: Copy Constructor::
Member:Copy Constructor::
Value is C2:
Parent::2
Member& ::2
Child 2
*/
/*return os << (Parent&)c << c.m 
Since the compiler then sees it as a Parent, it calls the Parent version of operator<<.
You can see that Child has no explicitly-defined copy-constructor. The compiler then synthesizes the copy-constructor
 (since that is one of the four functions it will synthesize, along with the default constructor – if you don’t create any 
 constructors – the operator= and the destructor) by calling the Parent copy-constructor and the Member copy-constructor.
  This is shown in the output 

Child(const Child& c) : i(c.i), m(c.m) {}
then the default constructor will automatically be called for the base-class part of Child, since that’s what the compiler 
falls back on when it has no other choice of constructor to call (remember that some constructor must always be called for 
every object, regardless of whether it’s a subobject of another class). The output will then be:

Parent(int ii)
Member(int ii)
Child(int ii)
calling copy-constructor:
Parent()
Member(const Member&)
values in c2:
Parent: 0
Member: 2
Child: 2
This is probably not what you expect, since generally you’ll want the base-class portion to be copied from the existing
 object to the new object as part of copy-construction.

To repair the problem you must remember to properly call the base-class copy-constructor (as the compiler does) whenever 
you write your own copy-constructor. This can seem a little strange-looking at first but it’s another example of upcasting:

  Child(const Child& c)
    : Parent(c), i(c.i), m(c.m) {
    cout << "Child(Child&)\n";
 }
*/
