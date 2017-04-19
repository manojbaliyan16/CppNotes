#include <iostream>

template <typename T>
const T& max(const T& x,const T& y){
	return (x>y) ? x : y;
}
int main(){
	int i=max(3,7);
	std::cout<<"Max:int "<<i<<std::endl;
	double d=max(4.5,7.6);
	std::cout<<"Max:double "<<d<<std::endl;
	char c=max('b','c');
	std::cout<<"Max:char "<<c<<std::endl;

}