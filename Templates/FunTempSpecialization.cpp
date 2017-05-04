#include <iostream>
template <class T>


class Storage
{ 
	T m_value;
public:
	Storage(T value){
		m_value=value;
	}
	~Storage(){
		
	}
void print(){
	std::cout<<m_value<<'\n';
}	
};

int main(){
	Storage<int> nvalue(5);
	Storage<double> dvalue(6.7);
	nvalue.print();
	dvalue.print();


}