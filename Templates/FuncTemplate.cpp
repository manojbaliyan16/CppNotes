#include <iostream>
using namespace std;

/*

class cent{
	int m_cents;
public:
	cent(int cents):m_cents(cents){}
	friend bool operator>(const cent& c1, const cent& c2){
		return(c1.m_cents>c2.m_cents); 
	} 
	friend ostream& operator<<(ostream& out, const cent& cents){
		out << cent.m_cents<< "cents";
		return out;
}
void operator+=(cent cents){
	m_cents+=cent.m_cents;
}
void operator/=(int value){
	m_cents/=value;
}
};*/
template <typename T>
 T average(const T* array, int length)
{
    T sum=0;
    for(int count=0;count<length;++count){
    	sum+=array[count];
    }
    sum /=length;
    return length;
}
class Cents
{
private:
    int m_cents;
public:
    Cents(int cents)
        : m_cents(cents)
    {
    }
 
    friend bool operator>(const Cents &c1, const Cents &c2)
    {
        return (c1.m_cents > c2.m_cents);
    }
 
    friend ostream& operator<< (ostream &out, const Cents &cents)
    {
        out << cents.m_cents << " cents ";
        return out;
    }
 
    void operator+=(Cents cents)
    {
        m_cents += cents.m_cents;
    }
 
    void operator/=(int value)
    {
        m_cents /= value;
    }
};
int main(){
	Cents array3[]={Cents(5),Cents(10),Cents(15),Cents(14)};
	cout<<average(array3,4);
	//std::cout<<bigger<<'\n';
}