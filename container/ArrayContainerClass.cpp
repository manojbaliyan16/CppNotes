#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <cassert>

using namespace std;

class IntArray{
	int m_length;
	int *m_data;
public:
	IntArray():m_length(0),m_data(nullptr){}
	IntArray(int length)
	{
		m_length=length;
		m_data=new int[length];
	}
	~IntArray()
	{
		delete [] m_data;
	}
	void erase(){
		delete [] m_data;
		m_data=nullptr;
		m_length=0;
	}
int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }
int getlength(){
	return m_length;
}
void reallocate(int newLength);
void resize(int newLength);
void insertBefore(int value, int index);
void remove(int index);
void InsertAtbegnining(int value);
void InsertAtEnd(int value);

};
#endif
void IntArray::reallocate(int newLength)
{
	erase();
	if(newLength <= 0)
		return ;
	m_data=new int[newLength];
	m_length=newLength;

}
void IntArray::resize(int newLength){
	if(newLength==m_length)
		return;
	if(newLength<=0){
		erase();
		return;
	}
	int* data=new int[newLength];
	if(m_length>0)
	{
		int elmenetToCopy = (newLength > m_length) ? m_length : newLength;
		for (int i = 0; i < elmenetToCopy; ++i)
		{
			data[i]= m_data[i];
		}
	}
delete [] m_data;
// TODO
m_data=data;
m_length=newLength;
}

void IntArray::insertBefore(int value, int index)
{
	  assert(index >= 0 && index <= m_length);
	int* data = new int[m_length+1];
	for (int i = 0; i < index; ++i)
	{
		data[i]=m_data[i];
	}
	data[index]=value;
	for (int i = index; i < m_length; ++i)
	{
		data[i+1]=m_data[i];
	}
	delete [] m_data;
	m_data=data;
	++m_length;
}
void IntArray::remove(int index)
{
	 assert(index >= 0 && index < m_length);
 
        // If this is the last element in the erase, set the array to empty and bail out
        if (m_length == 1)
        {
            erase();
            return;
        }
	int *data=new int[m_length-1];
	for (int before = 0; before < index; ++before)
	{
		data[before]=m_data[before];
	}
	for (int after = index+1; after < m_length; ++after)
	{
		data[after-1]=m_data[after];
	}
	delete [] m_data;
	m_data=data;
	--m_length;
}
void IntArray::InsertAtbegnining(int value)
{
	insertBefore(value,0);
}
void IntArray::InsertAtEnd(int value)
{
	insertBefore(value,m_length);
}



int main(){
	IntArray array(10);
	//fill the value in to array
	for (int i = 0; i < 10; ++i)
	{
		array[i]=i+1;
	}
//Resize to 8 element
	array.resize(8);
//insert element 20 before element with index 5
	array.insertBefore(20,5);
//Remove the Element with index 3;
	array.remove(3);
//Insert 15 at begining 
	array.InsertAtbegnining(30);
//insert 20 at end
	array.InsertAtEnd(40);
for (int i = 0; i < array.getlength(); ++i)
{
	cout<<array[i]<<" ";
}
}