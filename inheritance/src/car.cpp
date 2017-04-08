#include <iostream>


using namespace std;


class Engine{
public:
	void start() const{}
	void rev() const{}
	void stop() const{}
};

class Wheel{
public:
	void inflate(int psi) const{}
};
class Window{
public:
	void rollup(){}
	void rolldown(){}
};
class Door{
public:
	Window window;
	void open() const{}
	void close() const{} 
};
class Car{
public:
	Engine engine;
	Wheel wheel[4];
	Door left, right;
};
int main(){
	Car car;
	car.left.window.rollup();
	car.wheel[0].inflate(72);
}//Here to use composition is good makein meber public will help the client how to use the car and require less less code complexit
// Here no sense to make car is a vechile object beacuse car doesn't contain the vechile 
//The is a relationship is expressed with Inheritance and Has a relationship is expresse with Composition
