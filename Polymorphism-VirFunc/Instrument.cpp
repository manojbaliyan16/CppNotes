#include <iostream>
using namespace std;
enum note{middleC, csharp, Cflute};

class Instrument{
public:
	virtual void play(note) const=0;
		
	virtual char* what() const=0;
		//Assume this will Modify The Object
	virtual void adjust(int)=0;
};
class Wind : public Instrument{
public:
	void play(note) const{
		cout<<"Wind Play::"<<endl;
	}
	char* what() const{
		return "Wind";
	}
	void adjust(int){

	}
};
class Percussion : public Instrument{
	public:
		void play(note) const{
		cout<<"Percussion Play::"<<endl;
	}
		char* what() const{
		return "Percussion";
	}
		void adjust(int){

	}
};
class Stringed : public Instrument {
public:
  void play(note) const {
    cout << "Stringed::play" << endl;
  }
  char* what() const { return "Stringed"; }
  void adjust(int) {}
};
class Brass : public Wind {
public:
  void play(note) const {
    cout << "Brass::play" << endl;
  }
  char* what() const { return "Brass"; }
};
class Woodwind : public Wind {
public:
  void play(note) const {
    cout << "Woodwind::play" << endl;
  }
  char* what() const { return "Woodwind"; }
};

void tune(Instrument& i) {
  // ...
  i.play(middleC);
}

void f(Instrument& i) { i.adjust(1); 
}

Instrument* A[] = {
  new Wind,
  new Percussion,
  new Stringed,
  new Brass,
};

int main() {
  Wind flute;
  Percussion drum;
  Stringed violin;
  Brass flugelhorn;
  Woodwind recorder;
  tune(flute); //Wind Play::
  tune(drum);  //Percussion Play::	
  tune(violin); //Stringed::play
  tune(flugelhorn); //Brass::play
  tune(recorder); //Woodwind::play"
  f(flugelhorn);
} ///:~
/*
Wind Play::
Percussion Play::
Stringed::play
Brass::play
Woodwind::play
*/