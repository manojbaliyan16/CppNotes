//CopyConstructor and Casting	
#include <iostream>
#using namespace std;


class Parent{
	int i;
	Parent(const Parent& b);i(b.i){
		cout << "In Parent Copy Constructor"<<endl;
	}
	Parent(int ii=0):i(ii){
		cout << "In parent Default parent Constructor::"<< endl;
	}
	friend
};

