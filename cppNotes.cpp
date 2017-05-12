Template expression parameters
Expression parameters:
A template expression parameter is a special type of parameter that does not substitute for a type, but is instead replaced by a value. 
An expression parameter can be any of the following:
A value that has an integral type or enumeration
A pointer or reference to a class object
A pointer or reference to a function
A pointer or reference to a class member function



Effective C++ : 
Explicit constructor prevent the compiler from implicit type conversion.
Void dosomething(B obj);
B obj1;
Dosomething(obj1); /fine as dosomething() used object of B
B obj2;
Dosomething(28);/ if constructor is Explicit then compiler will give an error 
So for this 
Dosomething(B(28));
Constructor declare explicit usually prefer.

Copy Constructor : is used to initialized an object with a different object of sametype 	and copy assignement operator is used to copy from one object to another object of sametype.
Example:
Class Widget{
Public:
Widget(){} //defualt constructor
Widget(const Widget& rhs) {}// copy constructor
Widget& operator=(const Widget& rhs){} //copy assignment operator
};  
int main(){
	Widget w1; //defalt constructor called 
	Widget w2(w1); //copy Constructor called
	w2=w1; copy assignement operator called 

	Widget w3=w2;//invoke copy construtor

}
means if a new constructor is defined then copy constructor is invoked else copy assignemtn operator is invoked 
	when user pass by value ie object in to func is passed by value then copy constructor is invoked however it
	is a bad idea to pass the user defined type, pass-by-refernce-to-const is typically a better idea 


		# define v/s Const.
	#define ASPECTRATIO 1.653
	here symbol ASPECTRATIO will be removed by the preprocessor and for compiler there is only 1.653 so there is 
	no entry of ASPECTRATIO in the symbol table if this defines is written in one of the headerfile which is used by programmer 
	os if any error occur at define only 1.653 will come so it is very hard to find out why it is coming 
	so instead of define we can use 
	const double AspectRatio=1.653 as AspectRatio is an const double so there will be an entry of this in to symbol table 
	and it will be easy to debug 


	Usually c++ require provids the defination whatever you are declaring

	const int classname::variablename;
	enum hack 
class GamePlayer{
	enum {num=5};
	int score[num]; // it behaves more like a #define then like a const 
};
it is legal to take the address of the const but to take the address of enum or define is not legal
Qus: If you dont want to let people get a pointer or refernce of your Integral const then what you will do 
Ans : enum is the best answer 
Things to Remember
✦ For simple constants, prefer const objects or enums to #defines.
✦ For function-like macros, prefer inline functions to #defines

for const object means particular object should not be modified and compiler enforce this restrcition.
 compiler is to follow the restriction that the object will remain invariant when communication is going on 
 bewtween function or program 
 const is versaltile out side the class it can be used for static or name space and inside the class it can be used for 
 static and non static data_member

 you can ensure that weather pointer is const or data it points to is const or both or niether 

 char greeting[]="hello" //nothing is const 
 						// no const pointer
 						// no const data

 	const char* p=greeting; //no const poniter 		
 							// but const data means "hello" can't be modified 
 	char* const p=greeting; // no const data 
 							// const pointer

 	const char* const p=greeting;
 	if the const appers to the left of * what pointed will be const but if const appers to be the right of * the poniters itself is const.

 		here const char* p=greeting;
 		or char const* p=greeting; both are same;


const to fucntion declartion 
class Rational{};
const Rational operator*(const Rational& lhs, const Rational& rhs);
Now question is why function should return const value 
Ans: 
if we function return value is not const then client would be able to commit atroctities like below 
Rational a, b, c;
(a*b)=c; which will invoke = operator on the result of a*b!


const member function:
The purpose of const memeber function is which memeber function is to be invoked on const objects. 
one of the fundamental way to improve the c++ performance is to increase is the pass object by refernce to const 
it is good that never modify return value of function which return built in type


Things to Remember:
Declaring something const helps compilers detect usage errors. const
can be applied to objects at any scope, to function parameters and
return types, and to member functions as a whole.
✦ Compilers enforce bitwise constness, but you should program using
logical constness.
✦ When const and non-const member functions have essentially identical implementations, code duplication can be avoided by having the
non-const version call the const version.Declaring something const helps compilers detect usage errors. const
can be applied to objects at any scope, to function parameters and
return types, and to member functions as a whole.
✦ Compilers enforce bitwise constness, but you should program using
logical constness.
✦ When const and non-const member functions have essentially identical implementations, code duplication can be avoided by having the
non-const version call the const version.
Item 4:
make sure that object is initialized before they used :
the reponsibility of initilization is falls on the constructor 
class phoneNumber{};
class ABEntry{
	public:
	ABEntry(const string& name, const string& address, list<phoneNumber>&Phones)
private:
	string TheName;
	string TheAddress;
	list<phoneNumber> ThePhones;
	int NumTimesCalculated;
};
ABEntry::ABEntry(const string& name, const string& address, list<phoneNumber>&Phones){
	TheName=name;
	TheAddress=address;
	ThePhones=Phones;
	NumTimesCalculated=0;
	//These are all assignments not the Initialization 
	//no need to be confus between Initialization and assignments, this is not the best approach as C++ says
	// that datamember of the objects shall be initialized before entring in to the body of the constructor and in 
	the body of ABEntry this is the assignments while initilization already happened when default constrctor is called 
	but this is not true for NumTimesCalculated because it is built in type so there is no garaunttee that this already 
	initilaed or not so a better way to use member initialization list
	ABEntry::ABEntry(const string& name, const string& address, list<phoneNumber>&phones):TheName(name),TheAddress(address),ThePhones(Phones),
	NumTimesCalculated(0){} this is initialization.
}
if any class store the reference of object passed to the constructor arguments or class have const variable then it is mandotory 
to use the constructor initilization list.
Other reson to Use member initializ list 
1. Base class Initialization:
As base class should be constructed before the child class so if the base class have default construtor then there 
is no problem but if base class doesn't have any defaault construtor then it is mandatory to use member initilize 
list in to parameterize of the base class to ensure that ur base class is initialized before the child class 
2. Initialization of subobjects which only have parameterized construtor 
3. efficiency 
4. Initialization of non static data members
5. Initialization of reference data member : Reference datamember should be initialized where they are declared 
and it is possible with member initialization list.

Static Object: A static Object is one which is exist from the time it is constructed till the program ends
static object declared inside the function is called local static object bcz this scope with in the function itself 
static object distructor is called when main finishes its execution. 

Chapter 2:	
Constructor, distructor & Assignment operator:
