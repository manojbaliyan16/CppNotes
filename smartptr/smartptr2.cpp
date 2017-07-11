#include <iostream>
#include <vector>

using namespace std;



class Employee{
	private:
	int ID;
	int Salary;
	public:
	Employee(int I, int Sal):ID(I),Salary(Sal){}
	void show(){
		cout<<"Employee Id is ::"<<ID<<endl;
		cout<<"Salary of the Employee is ::"<<Salary<<endl;
	}
	~Employee(){
		cout<<"Distructor Called of Employee"<<endl;
	}

};

class SmartPointer{
	private:
	Employee *data;
	public:
	SmartPointer(Employee* ptr):data(ptr){}
	~SmartPointer(){
		cout<<"Distructor Called of SmartPointer"<<endl;
		delete data;
	}
	Employee& operator*(){
		return *data;
	}
	Employee* operator->(){
		return data;
	}
};


int main(){
	SmartPointer p(new Employee(101,20000));
	p->show();
}