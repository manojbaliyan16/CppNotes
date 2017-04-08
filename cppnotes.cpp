Composition:
You simply create objects of your existing class inside the new class. This is called composition because the new class is
Composed of objects of existing classes.
Y contains a subobject of X: As per useful.cpp  Both member objects and base class storage are referred to as subobjects.

The constructor initializer list:
The solution is simple: Call the constructor for the subobject. C++ provides a special syntax for this, the constructor initializer list. The form of the constructor initializer 
list echoes the act of inheritance. With inheritance, you put the base classes after a colon and before the opening brace of the class body. In the constructor initializer list, you put the calls to subobject constructors after the constructor argument list and a colon, but before the opening brace of the function body. For a class MyType, inherited from Bar, this might look like this:

MyType::MyType(int i) : Bar(i) { // ...
if Bar has a constructor that takes a single int argument.

	Member object initialization

It turns out that you use this very same syntax for member object initialization when using composition.
For composition, you give the names of the objects instead of the class names. If you have more than one 
constructor call in the initializer list, you separate the calls with commas:

MyType2::MyType2(int i) : Bar(i), m(i+1) { // ...
This is the beginning of a constructor for class MyType2, which is inherited from Bar and contains a member 
object called m. Note that while you can see the type of the base class in the constructor initializer list, 
you only see the member object identifier.

Overriding 
It’s worth emphasizing that constructors and destructors are quite unusual in that every one in the hierarchy is called,
 whereas with a normal member function only that function is called, but not any of the base-class versions. 
 If you also want to call the base-class version of a normal member function that you’re overriding,
  you must do it explicitly.


 NameHiding 
 If you inherit a class and provide a new definition for one of its member functions, there are two possibilities.
  The first is that you provide the exact signature and return type in the derived class definition as in the base class
   definition. This is called redefining for ordinary member functions and overriding when the base class member function is a virtual function (virtual functions are the normal case, and will be covered in detail in Chapter 15).
  But what happens if you change the member function argument list or return type in the derived class? Here’s an example:
  NameHiding.cpp

  Functions that don’t automatically inherit//TODO

  1.constructors and destructors don’t inherit and must be created specially for each derived class.
  2.In addition, the operator= doesn’t inherit because it performs a constructor-like activity. That is, just because you know how to assign all the members of an object on the left-hand side of the = from an object on the right-hand side doesn’t 
  mean that assignment will still have the same meaning after inheritance.

  Inheritance and static member functions
  static member functions act the same as non-static member functions:
  1. They inherit into the derived class.
  2. If you redefine a static member, all the other overloaded functions in the base class are hidden.//TODO
  3.If you change the signature of a function in the base class, all the base class versions with that function name are hidden 
  (this is really a variation of the previous point).
 4. Static Member Function can be not be virtual 


 Choosing composition vs. inheritance

Composition is generally used when you want the features of an existing class inside your new class, but not its 
interface. That is, you embed an object to implement features of your new class, but the user of your new class
sees the interface you’ve defined rather than the interface from the original class. To do this, you follow the typical 
path of embedding private objects of existing classes inside your new class.
Occasionally, however, it makes sense to allow the class user to directly access the composition of your new class, 
that is, to make the member objects public. The member objects use access control themselves, so this is a safe thing
 to do and when the user knows you’re assembling a bunch of parts, it makes the interface easier to understand.
  A Car class is a good example:car.cpp