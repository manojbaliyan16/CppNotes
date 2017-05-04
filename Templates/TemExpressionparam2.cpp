#include <iostream>
#include <string.h>
#include <cstdlib>

template <class T, int size>

class Buffer{
private:
	T m_buffer[size];
public:
	T* getBuffer(){
		return m_buffer;
	}
	T& operator[](int index){
		return m_buffer[index];
	}
};
template<int size>
void printBuffer(Buffer<char,size>& obj_buffer)
{
	std::cout<<obj_buffer.getBuffer()<<std::endl;
}

int main()
{
	Buffer<int, 12> StaticArray; //int StaticArray[12];
	for (int i = 0; i < 12; ++i)
	{
		StaticArray[i]=i;
	}
	for (int i = 11; i >= 0; --i)
	{
		std::cout<<StaticArray[i]<<" ";
	}
	std::cout<<'\n';
	/*Buffer<char, 31> charBuffer //char charBuffer[31]
	strcpy_s(charBuffer.getBuffer(), 31, "hello Travel!");
	std::cout<<charBuffer.getBuffer()<<std::endl;
*/
}
