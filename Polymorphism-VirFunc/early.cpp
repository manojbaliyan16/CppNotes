#include <iostream>

using namespace std;

class Pet{
		public:
			virtual string speak() const{
				return "BASE";
			}
};
class Dog : public Pet{
public:
	virtual string speak() const{
			return "BARK!!";
		}
	};
int main(){
	Dog ralph;
	Pet* p1=&ralph;
	Pet& p2=ralph; 

	// P1 and P2 are having the address and p1->speak() and p2->speak() doesn't know the exact 
	//type  of the object so Virtual Mechanish is used 
	Pet p3; // here compiler knows exact type of the object so if compiler will take the load then base calss
	// func will be called 
	// Late binding for both:
  cout << "p1->speak() = " << p1->speak() <<endl;
  cout << "p2.speak() = " << p2.speak() << endl;
  // Early binding (probably):
  cout << "p3.speak() = " << p3.speak() << endl;
	return 0;
}