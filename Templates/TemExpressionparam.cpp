// Template Expression Parameter 
/*
Generally, template expression parameters are a good choice when you can live with static memory allocation 
(e.g. arrays that are sized at compile time). Having the constructor create m_array requires dynamic memory allocation, 
which adds complexity (but also allows other things such as dynamic resizing and the memory comes from the heap instead 
of the stack, which is beneficial for large arrays).
	*/
#include <iostream>
template <class T, int size>
class StaticArray{
	T m_array[size];
public:
	T* getArray();

	T& operator[](int index)
	{
		return m_array[index];
	}
	
};
template <class T, int size>
T* StaticArray<T, size>::getArray()
{
	return m_array;
}


int main(){
	StaticArray<int,12> intarray;
	for (int count = 0; count < 12; ++count)
	{
		
		intarray[count]=count;
	}
	for (int count = 11; count >=0; --count)
	{
	
		std::cout<<intarray[count]<<" ";
		
	}
	std::cout<<'\n';
	StaticArray<double, 4> doubleArray;

	for (int count=0; count < 4; ++count)
        doubleArray[count] = 4.4 + 0.1*count;

	for (int i = 0; i < 4 ; ++i)
	{
	
		std::cout<<doubleArray[i]<<' ';
	}
	std::cout<<'\n';
	return 0;
}
