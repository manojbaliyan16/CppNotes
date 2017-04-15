#include <iostream>
using namespace std;


class A{
	int i;
public:
	A(){
		cout<<"Constructor A::"<<endl;
	}
};
class B{
	int i;
	public:
	B(){
		cout<<"Constructor B::"<<endl;
	}
};
class C: public A{
	B b;
	public:
		// C():b(),A(){
		// 	cout <<"Constructor C::"<<endl;
		// }
};
int main(){
	C c;
}
//Observation : With Out Creation of Constructor for c it is working fine 
