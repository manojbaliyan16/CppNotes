#include <iostream>
using namespace std;

class Shape{
public:
virtual void draw() const{
	cout << "Draw the shape"<<endl;
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
/*Shape* A[] = { new Circle,new Square,new Traingle};

for(int i=0;i<3;i++){
	A[i]->draw();
}
*/

	//Circle c1;
	//Square s1;
	//Traingle t1;
	//Shape* bp[] = {&c1,&s1,&t1};
Shape* bp[] = { new Circle,new Square, new Traingle};

for(int i=0;i<3;i++)
{
	bp[i]->draw();
}
}	