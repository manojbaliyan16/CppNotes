#include <iostream>
using namespace std;

class MyError{
const char* const data;
public:
	MyError(const char* const msg=0):data(msg){}
};
void f(){
	throw  MyError("SomeThing Bad Happened");
}

int main(){
	try {
		cout<<"In Try\n";
		f();
	}
	catch(MyError	){
		cout<<"Exception Catched\n";
	}
}