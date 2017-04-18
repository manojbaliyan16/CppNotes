#include <iostream>
using namespace std;
class Pet
{
	public:
		virtual ~Pet(){}
};
class Dog:public Pet{};
class Cat:public Pet{};
int main(){
	//Pet* bp=new Dog;//upcast
	Pet* bp1=new Cat;//upcast cat pointer upcast to pet
	//try to cast it to DOG
	Dog* d1=dynamic_cast<Dog*>(bp1); //downcast to DOG Ponitter which s wrong so return zero
	Cat* d2=dynamic_cast<Cat*>(bp1); //	//downcast to Cat Ponitter which returns address
	cout<<"bp1=   ="<<(long)bp1<<endl;
	cout<<"d1=   ="<<(long)d1<<endl;//downcast to  is 
	cout<<"d2=   ="<<(long)d2<<endl;
}
/*
bp1=   =93884189473824
d1=   =0
d2=   =93884189473824
*/