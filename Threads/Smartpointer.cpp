/*
 * Smartpointer.cpp
 *
 *  Created on: 04-Jul-2017
 *      Author: baliyan
 */
#include <iostream>
#include <vector>
#include <stdio.h>



class Person
{
    int age;
    char* pName;

    public:
        Person(): pName(0),age(0)
        {
        }
        Person(char* pName, int age): pName(pName), age(age)
        {
        }
        ~Person()
        {
        }

        void Display()
        {
            printf("Name = %s Age = %d \n", pName, age);
        }
        void Shout()
        {
            printf("Ooooooooooooooooo");
        }
};
class SP{
private:
	Person* pdata;//pointer to person class
public:
	SP(Person* pvalue):pdata(pvalue){}
	~SP(){delete *pdata;}
	Person& operator*()
	{
		return *pdata;
	}
	Person* operator->()
	{
		return pdata;
	}
};
/*int main()
{
    Person* pPerson  = new Person("Scott", 25);
    pPerson->Display();
    delete pPerson;
}*/
int main()
{
    SP p(new Person("Scott", 25));
    p->Display();
    // Dont need to delete Person pointer..
}
/*
Every time I create a pointer it is mandatory to delete this
//
 // A pointer can be delted in to destructor but pointer does not hve the destructor but
  * smartpointer is to have the destructor
  *
	so lets have a class for the smart pointer say SP and the interface for the smart pointer will be similiar to the
	pointers bcz it will do the things what pointer can do
means Dereferencing operator
and inderection -> *
*/

