#include <iostream>
#include "../inc/useful.h"
using namespace std;

class Y{
int i;
X x;//embedded Object or composition, generally Embedded Object is Private 
public:
Y(){
	i=0;
}

void f(int ii){
	i=ii;
	x.set(ii);
}
int g() const{

	return i*x.read();
}
void permute(){
	x.premute();
}
};
int main(){
	Y y;
	y.f(47);
	y.permute();
}

