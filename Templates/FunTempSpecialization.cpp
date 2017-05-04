/*
Simple Template Class 

*/
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
	void print();
/*void print(){
	std::cout<<"manoj"<<m_value<<'\n';
}	*/
};
template<>
void Storage<int>::print(){
	std::cout<<"manoj"<<m_value<<'\n';
}	
template <>
void Storage<double>::print(){
	std::cout << std::scientific << m_value << '\n';
}

int main(){
	Storage<int> nvalue(5);
	Storage<double> dvalue(6.7);
	nvalue.print();
	dvalue.print();


}