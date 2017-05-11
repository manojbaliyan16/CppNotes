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
	pasge number 35
	const int GamePlayer::NumTurns; 
