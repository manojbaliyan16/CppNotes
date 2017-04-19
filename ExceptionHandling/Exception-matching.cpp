#include <iostream>

using namespace std;
class Exception1{

};
class Exception2{
public:
	Exception2(const Exception1&){}

};
void f(){
	throw Exception1();
}
int main(){
try{
	f();

}catch(Exception1&){
	cout<<"Inside Catch Exception1\n";
}
catch(Exception2&){
	cout<<"Inside Catch Exception2\n";
}

}
/*Inside Catch Exception1
*/