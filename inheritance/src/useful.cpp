#include <iostream>
#include "../inc/useful.h"
using namespace std;

class Y{
int i;
public:
Y(){
	i=0;
}
X x;//embedded Object or composition
void f(int ii){
	i=ii;
}
int g() const{
	return i;
}

};
int main(){
	Y y;
	y.f(47);
	y.x.set(37);
}

