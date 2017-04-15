#include <iostream>
using namespace std;
enum note{MiddleC, CSharp, Cflat};
class Instrument{
public:
	virtual void play(note) const{
		cout<<"Instrument Play Note"<<endl;
	}
};

class Wind : public Instrument{
public:
	void play(note) const{
		cout<<"Wind Play Note"<<endl;
	}
};

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
/*The function tune( ) accepts (by reference) an Instrument, but also without complaint anything derived from Instrument. 
In main( ),you can see this happening as a Wind object is passed to tune( ), with no cast necessary. This is acceptable; the interface 
 in Instrument must exist in Wind, because Wind is publicly inherited from Instrument. Upcasting from Wind to Instrument may 
 “narrow” that interface, but never less than the full interface to Instrument.

The same arguments are true when dealing with pointers; the only difference is that the user must explicitly take the addresses 
ts as they are passed into the function.*/
/*here we are passing object of wind to call the function Tune but 
Here Problem is only: Instrument::play() is called, So To Understand this issue we have to under stand concept of binding */