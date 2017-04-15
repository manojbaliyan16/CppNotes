#PriateInheritance 
/*
You may wonder what the purpose of private inheritance is, because the alternative of using composition to 
create a private object in the new class seems more appropriate. private inheritance is included in the 
language for completeness, but if for no other reason than to reduce confusion, you’ll usually want to use 
composition rather than private inheritance. However, there may occasionally be situations where you want to 
produce part of the same interface as the base class and disallow 
the treatment of the object as if it were a base-class object. private inheritance provides this ability.

Publicizing privately inherited members

When you inherit privately, all the public members of the base class become private. If you want any of them to 
be visible, just say their 
names (no arguments or return values) along with the using keyword in the public section of the derived class:
*/
#inclue <iostream>
using namespace std;	
class Pet{
	char eat const{ return "a" ;}
	int speak() const { rerurn 2;}
	int sleep() const { return 3;}
	int sleep(int) const { return 4;}

};
class GoldFish:Pet{
public:
	using Pet::eat;
	using Pet::sleep;//Both Overload member Exposed
};
int main(){
	GoldFish bob;
	bob.eat();
	bob.sleep();
	bob.sleep(1);
	//bob.speak(); //Error beacause it is Private 
}