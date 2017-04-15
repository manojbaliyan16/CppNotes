// Pure virtual base definitions
#include <iostream>
using namespace std;

class Pet {
public:
  virtual void speak() const = 0;
  virtual void eat() const = 0;
  // Inline pure virtual definitions illegal:
  //!  virtual void sleep() const = 0 {}
};

// OK, not defined inline
void Pet::eat() const {
  cout << "Pet::eat()" << endl;
}

void Pet::speak() const { 
  cout << "Pet::speak()" << endl;
}

class Dog : public Pet {
public:
  // Use the common Pet code:
  void speak() const { 
    cout<<"DOG::SPEAK()"<<endl;
    Pet::speak();
     }
  void eat() const { Pet::eat(); }
};

int main() {
  Dog simba;  // Richard's dog
  simba.speak(); //
  simba.eat();
}
/*The slot in the Pet VTABLE is still empty, but there happens to be a function by that name that you can call
 in the derived class. The other benefit to this feature is that it allows you to change from an ordinary virtual 
 to a pure virtual without disturbing the existing code. (This is a way for you to locate classes that don’t 
 override that virtual function.)*/
