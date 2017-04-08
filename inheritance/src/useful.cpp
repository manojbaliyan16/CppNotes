#include <iostream>
#include "../inc/useful.h"
using namespace std;

class Y:public X{
int i; //different from X's i
// no need of embedded Object
public:
Y(){
	i=0;
}
int change(){
	i=premute();//This is How we can call to Different Name function Call Of class X 
	return i;
}

void set(int ii){
	i=ii;
	X::set(ii);// This is how we can call the Same name Fucntion Call 
}

};
/*
int main(){
cout << "Size Of (X)==" << sizeof(X) << endl;
cout << "Size Of (Y)==" << sizeof(Y) << endl;
Y D;
D.change();
// X's funciton Interface Comes Through
D.read();
D.premute();
//Redefined functions Hide base Version 
D.set(12);
}
*/

