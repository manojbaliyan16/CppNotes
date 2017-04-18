#include <iostream>

class Shape{
public:
virtual void draw() const{
	cout << "Draw the shape">>endl;
}

};

class Circle:public Shape{
public:
	void draw() const{
		cout<<"Drawn Circle"<<endl;
	}
};
class Square:public Shape{
	public:
	void draw() const{
		cout<<"Drawn Square"<<endl;
	}
};
class Traingle:public Shape{
	public:
	void draw() const{
		cout<<"Drawn Traingle"<<endl;
	}
};
	
int main(){
	
}	