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


