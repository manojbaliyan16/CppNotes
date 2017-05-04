#include <iostream>
#include "array.h"
//solution 1
//#include "array.cpp"


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
/*
	if we make array.cpp and in thi sfile we put defination of getlength() which is the member function of Tempaled Array class 
	(In general it is comman behavior) so liner error is here that is :
	CMakeFiles/Array.dir/ArraySrc/main.cpp.o: In function `main':
	main.cpp:(.text+0x50): undefined reference to `Array<int>::getlength()'
	main.cpp:(.text+0xaf): undefined reference to `Array<int>::getlength()'
	collect2: error: ld returned 1 exit status
	it is because In order for the compiler to use a template, it must see both the template definition (not just a declaration) 
	and the template type used to instantiate the template.
	Also remember that C++ compiles files individually. When the Array.h header is #included in main, the template class definition is copied into main.cpp. When the compiler sees that we need two template instances, Array<int>, and Array<double>, it will instantiate these, and compile them as part of main.cpp. However, when it gets around to compiling Array.cpp separately,
	 it will have forgotten that we need an Array<int> and Array<double>, so that template function is never instantiated. 
	so the solution for this is 
	1. include array.cpp in main.cpp 
	or
	2. template class Array<int>; // Explicitly instantiate template Array<int>
template class Array<double>; // Explicitly instantiate template Array<double>
	*/