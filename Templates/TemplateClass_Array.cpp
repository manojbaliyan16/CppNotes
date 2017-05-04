	#include <iostream>
	#include <assert.h>

	#ifndef ARRAY_H
	#define ARRAY_H

	template <class T>
	class Array{
	private:
		int m_length;
		T* m_data;
	public:
		Array(){
			m_length=0;
			m_data=0;
		}
		Array(int length){
			m_length=length;
			m_data=new T[length];
		}
		~Array(){
			delete [] m_data;
		}
		void erase(){
			delete [] m_data;
			m_data=0;
			m_length=0;
		}
		//Here Use of [] operator overloding is bcz we have to use with intarray[] and doublearray [] which is object of template class 
		T& operator[](int index){
			assert(index >= 0 && index < m_length);
			return m_data[index];
		}
		int getlength();
	};
	//memeber function defined uotside the class needs its own template and note that class name is Array<T> not Array
	//because Array would refer to not templated version of the class and Array<T>
	template <typename T>
	int Array<T>::getlength(){
		return m_length;
	}

	#endif

	int main(int argc, char const *argv[])
	{
		Array<int> intArray(12);
		Array<double> doubleArray(14);
		for (int count = 0;count<intArray.getlength(); ++count)
		{
			intArray[count]=count;
			doubleArray[count]=count+0.5;
		}
		for (int count = intArray.getlength()-1 ;count >=0; --count)
		{
			std::cout<< intArray[count] << " \t " << doubleArray[count] <<std::endl;
		}
		return 0;
	}
