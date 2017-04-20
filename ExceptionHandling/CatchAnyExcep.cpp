
#include <iostream>
using namespace std;

class X{
public:
	class Trouble{};
		class Big:public Trouble{};
		class Small:public Trouble{};
	void f(){throw (Trouble());}
};
int main(){
	X x;
	try{
		x.f();
	}
	catch(...){
		cout<<"caught Trouble\n";
	}
	
}
