#include "array.h"

template class Array<int>; // Explicitly instantiate template Array<int>
template class Array<double>; // Explicitly instantiate template Array<double>

template <typename T>
	int Array<T>::getlength()
	{
		return m_length;
	}