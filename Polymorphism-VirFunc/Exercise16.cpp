#include <iostream>
using namespace std;

class Pet {
  string pname;
public:
  Pet(const string& petName) : pname(petName) {}
  virtual string name() const =0;
  virtual string speak() const =0;
};
/*string Pet::name(){
  return pname;
}
*/
class Dog : public Pet {
  string name;
public:
  Dog(const string& petName) : Pet(petName) {}
  // New virtual function in the Dog class:
  virtual string sit() const {
    return Pet::namespace() + " sits";
  }
  string speak() const { // Override
    return Pet::name() + " says 'Bark!'";
  }
};

int main() {
  Pet* p[] = {new Dog("bob")};
  cout << "p[0]->speak() = "
       << p[0]->speak() << endl;
  cout << "p[1]->speak() = "
       << p[1]->speak() << endl;
         ((Dog*)p[1])->sit();
     /*
       p[1]->sit();	IT IS ILLEGAL BEACUSE here we are trying to access member function of the derived 
       class only with 
       // Base class Pointer */
   //((DOG*)p[1])->sit();	//it is possible with only with Casting 
cout << "(Dog*)p[1]->speak() = "
         <<((Dog*)p[1])->sit()<<endl;
   }
