#include <iostream>


template <typename T>
const T& max(const T& x, const T& y)
{
    return (x > y) ? x : y;
}
class cent{
	int m_cents;
public:
	cent(int cents):m_cents(cents){}
	friend bool operator>(const cent& c1, const cent& c2){
		return(c1.m_cents>c2.m_cents); 
	} 

};
int main(){
	cent nickle(5);
	cent dim(10);
	cent bigger=max(nickle,dim);
	//std::cout<<bigger<<'\n';
}