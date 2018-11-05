/*
 * Singleton.cpp

 *
 *  Created on: 09-Jun-2017
 *      Author: baliyan
 */
#include <iostream>
using namespace std;
class Singleton {
	Singleton() {
	}
	;
	static Singleton *single;
	static bool IsSingle;
public:

	static Singleton* getInsatnce();

	void method();
	~Singleton() {
		IsSingle = false;
	}

};
bool Singleton::IsSingle = false;
Singleton* Singleton::single = NULL;
Singleton* Singleton::getInsatnce() {
	
	if (!IsSingle) {
		single = new Singleton();
		IsSingle = true;
		return single;
	} else
		return single;
}
void Singleton::method() {
	cout << "Singleton Method Called \n";
}

int main() {

	Singleton *ptr1, *ptr2;
	ptr1 = Singleton::getInsatnce();
	ptr1->method();
	ptr2 = Singleton::getInsatnce();
	ptr2->method();
	// print the address of both pointer 
	cout << ptr1 << " ::: " <<  ptr2 <<endl;

}
