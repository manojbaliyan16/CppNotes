/*
 * Decorator.cpp
 *
 *  Created on: 09-Jul-2017
 *      Author: baliyan
 */
/*
 * Inheriting Behaviour at Run time through composition and delegators. Means When I inherit the behaviour by Subclassing,
 * Behaviour is set statically at compile time.
 * All subclass inherit the same behaviour if It extends through object composition same behaviour can be
* extends dynamically.
* By Dynamically Composing Object Means we can add new functionality or Responsiblity with out alerting the
* existing code As I am Not changing the existing code so Introduction of new Bug is very less.
*
 *Classes should be open for extension and Should be Closed for Modification
 *
 *The Decorator Pattern: It attach additional responsibilities to an object dynamically, Decorators Provide a flexible
  alternative to sub classing for extending functionality
  He
 Here We are using inheritance for type matching not for adding new behaviour, decorator needs the same interface as the
 component they wrap.
 With Composition we can mix and match the behaviour at nay time as we want and at runtime
and We can add any new decorator at any time as we want to add new behaviour

// but if rely on inheritance then at every time when we want to add new feature we have to change the existing code
// Decorator Design pattern is one of the behavioural Design pattern its provide the extra Flexibbility to the existing
 * type, So Decorator Design Pattermn Provide the SOLID rule to the developer
 * S: Single Responsiblity Principle: Class/Function should do only One Task or Should have one Reasong to change
 * Open-Close Principle: Class/Function Should be open for Extension but should be close for Modification
 * Liskov Subsitution Type :If Type S is derived from Type T then Object of Type T can Be replaced By S
 *
 * IComponent: Defines the operations or features that Decorator Can perform: having addToping() Method that all class will Implement This
 *
 * StartComponent/PlainIcecream:This is the starting Object That You can add features dynamically To it . You will create this Object frist and will
 * add new feature to it.
 * Topping/Decorator: The abstract class which is the parent class of all the decorator while It Implement the Icomponent
 * Interface to define its operation, it will also have an private member variable which ponits to the object to be decorated
 *This variable as input simple assigned in to its constructor.
 *In its constructor, it assigns the parameter of type IComponent to the input variable
 *

*/
#include <iostream>
#include <vector>
using namespace std;
//The client Code to use teh decorator
/*
IComponent a=new PlainIceCream(); // Starting Point
IComponent b=new PeanutTopping(a);//Notice I pass in to Icomponent and want to decorate
IComponent c=new CandyTopping(b); //Add another Decorator as User want candyTopping Also
c.AddTopping();//Do all The Operation of Addtopping() of Plain IceCream, PeanutTopping and CandyTopping
*/

class IComponent{
public:
	virtual void AddTopping()=0;
	virtual ~IComponent(){}
};
class PlainIceCream: public IComponent{
public:
	void AddTopping(){
		cout<<"Plain Ice Cream is Ready For Some Topping"<<endl;
	}
};

class Topping:public IComponent{
protected:
	IComponent* input;
public:

	Topping(IComponent* i):IComponent(){
		input=i;//store the Item to be Decorated
	}
	void AddTopping(){}

};

class CandyTopping:public Topping{
public:
CandyTopping(IComponent* i):Topping(i){}
void AddTopping(){
	input->AddTopping();
	cout<<"Candy Topping Added"<<endl;
}
};

class PeanutTopping:public Topping{
public:
	PeanutTopping(IComponent* i):Topping(i){}
void AddTopping(){
	input->AddTopping();
	cout<<"Peanut Topping  Added"<<endl;
}
};

int main(){
	IComponent *a=new PlainIceCream();
	IComponent *b=new PeanutTopping(a);
	IComponent *c=new CandyTopping(b);
	c->AddTopping();
}
