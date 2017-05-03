//Here I ll take example to creation an Int array and and Double array almost code is same in both the classes means here 
// we can use the Template class 


#ifndef INTARRAY_H
#define INTARRAY_H

#include <assert.h>

class IntArray{
private:
	int m_length;
	int* m_data;
public:
	IntArray(){
		m_length=0;
		m_data=0;
	}
	IntArray(int length){
		assert(length>0)
		m_data=new int[length];
		m_length=length;
	}
	~IntArray(){
		delete [] m_data;
	}
	void erase(){
		delete [] m_data;
		m_data=0;
		m_length=0;
	}
int getlength(){
	return m_length;
}
int& operator[](int index){
	assert(index > 0 && << m_length)
	return m_data[index];
}
};	

#endif
//if I have to create an array of double then code will be as follows 
#ifndef INTARRAY_H
#define INTARRAY_H

#include <assert.h>

class IntArray{
private:
	int m_length;
	int* m_data;
public:
	IntArray(){
		m_length=0;
		m_data=0;
	}
	IntArray(int length){
		assert(length>0)
		m_data=new int[length];
		m_length=length;
	}
	~IntArray(){
		delete [] m_data;
	}
	void erase(){
		delete [] m_data;
		m_data=0;
		m_length=0;
	}
int getlength(){
	return m_length;
}
int& operator[](int index){
	assert(index > 0 && << m_length)
	return m_data[index];
}
};	

#endif 
/*
#ifndef FLOATARRAY_H
#define FLOATARRAY_H

#include <assert.h>

class FloatArray{
private:
	int m_length;
	int* m_data;
public:
	FloatArray(){
		m_length=0;
		m_data=0;
	}
	FloatArray(int length){
		assert(length>0)
		m_data=new int[length];
		m_length=length;
	}
	~FloatArray(){
		delete [] m_data;
	}
	void erase(){
		delete [] m_data;
		m_data=0;
		m_length=0;
	}
int getlength(){
	return m_length;
}
int& operator[](int index){
	assert(index > 0 && << m_length)
	return m_data[index];
}
};	
// both the fucntion alomost same 
#endif*/