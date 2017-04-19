#include <iostream>
using namespace std;
	
	class Rainbow{
	public:
		Rainbow(){}
		~Rainbow(){}
	};

	void oz(){
		Rainbow rb;
		for(int i=0;i<3;i++)
			cout<<"There is no place like Home\n";
		throw 47;
	}
	int main(){
		try{
			cout<<"Delhi, Banglore, Pune\n";
			oz();
		}
		catch(int){
			cout<<"I had Stranges Dream\n";
		}
	}