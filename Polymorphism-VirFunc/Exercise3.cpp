#include <iostream>
using namespace std;

class Shape{
public:
virtual void draw() const{
	cout<<"Shape Drwan\n";
}
};

class Circle:public Shape{
public:
	
	void draw() const{
		cout<<"Drawn Circle"<<endl;
	}
};
/*
class Square:public Shape{
	public:
	void draw() const{
		cout<<"Drawn Square"<<endl;
	}
};

class Traingle:public Shape{
	public:
	void draw() const {
		cout<<"Drawn Traingle"<<endl;
	}
};*/
void describe(Shape& t){
	t.draw();
	
}

int main(){
//Shape* A=new Traingle;
//A->draw();
//Shape* A[] = { new Circle,new Square,new Traingle};
Shape t;
Circle C;
describe(t);
describe(C);

/*Circle* c1=dynamic_cast<Circle*>(A[0]);
Square* c2=dynamic_cast<Square*>(A[1]);
Traingle* c3=dynamic_cast<Traingle*>(A[2]);
c1->draw();
c2->draw();
c3->draw();*/
}	