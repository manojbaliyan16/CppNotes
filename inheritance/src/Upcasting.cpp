#include <iostream>
using namespace std;
enum note{MiddleC, CSharp, Cflat};
class Instrument{
public:
	void play(note) const{}
};

class Wind : public Instrument{};

void Tune (Instrument& i){

	i.play(MiddleC);
}

int main(){
	Wind flute;
	Tune(flute); //at defination of Tune we are passing the Instrument Object In Tune but here passing Wind flute, because Wind is 
	//child class and Parent is base class so here Upcasting explicitly Happen 
	//the code works for Instrument and anything derived from Instrument, and the act of converting a Wind
	 //reference or pointer into an Instrument reference or pointer is called upcasting.
}
