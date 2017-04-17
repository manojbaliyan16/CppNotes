#include <iostream>
#include <string>
using namespace std;
class Pet{
	string pname;
public:
	Pet(const string& name):pname(name){}
	virtual string name() const{
		return pname;
	}
	virtual string Description() const{
		return "this is " + pname;
	}
};
class DOG:public Pet{
	string favorateActivity;
public:
	DOG(const string& name, const string& Activity):Pet(name),favorateActivity(Activity){}
	string Description() const{
		return Pet::name()  + "likes to" + favorateActivity ;
	}
};
//Base Class Object is pass by value so Object will be slicedoff
void describe(Pet* p){ 
	cout<<p.Description()<<endl;

}

int main(){
	Pet p("Tony");
	DOG d("Ramu", "Sleep");
	describe(p);
	describe(d);	
}