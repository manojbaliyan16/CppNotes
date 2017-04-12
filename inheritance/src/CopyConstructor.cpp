#include <iostream>
using namespace std;

class Parent{
	int i;
public:
	Parent(int ii):i(ii){
		cout<<" Parent(int ii)" << endl;
	}
	Parent(const Parent& b):i(b.i){
		cout<<"Parent: Copy Constructor"<<endl;
	}
	Parent():i(0){
		cout << "Default Constructor "<< endl; 
	}
	friend ostream& operator<<(ostream& os, const Parent& right){ // friend fucntion as we have to take two argument 
		return os << "Parent ::" << right.i << endl;
	}
};

class Member{
	int i;
public:
	Member(int ii):i(ii){
		cout<<"Member(int ii)" << endl;
	}
	Member(const Member& b):i(b.i){
		cout << "Member: Copy Constructor"<< endl;
	}
	friend ostream& operator<<(ostream& os,const Member& m){
		return os << "Member & :"<< m.i << endl;
	}
};
class Child : public Parent{
	int i;
  Member m;
public:

	Child(int ii) : Parent(ii), i(ii), m(ii){
		cout << "child(int ii)"<<endl;
	}
friend ostream& operator<<(ostream& os, const Child& c){
	return os << (Parent&)c << c.m << "Child " << c.i << endl;
	}
};



int main(){
Child c(2);
cout << "Copy Constructor Called"<<endl;
Child c2=c;
cout << "Value is C2:\n "<< c2;
}