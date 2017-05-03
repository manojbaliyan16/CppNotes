/*
int max(int x, int y){
	return (x>y)?x:y;
}

template<typename T>//template parameter declaration
multiple type parameter template<typename T1, typename T2>

if the function argument passed in for the type T could be a class type and it is not good idea to pass classes by value 
it would be better to make the good idea to make arument and returns type as const refe
template<typename T>
const T& max(const T& x, const T& y){}

*/
#include <iostream>
template<typename T>
const T& max(const T& x, const T& y){
	return (x>y)?x:y;
}

int main(){
	int i=max(3,7);
	std::cout<<i<<'\n';
	double d=max(7.34, 5.35);
	std::cout<<d<<'\n';
	char c=max('a','b');
	std::cout<<c<<'\n';
}
