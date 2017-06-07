/*
 * Observer.cpp
 *
 *  Created on: 07-Jun-2017
 *      Author: baliyan
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>



using namespace std;
class IObserver{
public:
	virtual void update(float price)=0;
};

class ShopsOfObserver:public IObserver{
private:
	float price;
	string name;
public:
	ShopsOfObserver(string n){
		this->name=n;
	}
	void update(float price){
		this->price=price;
		cout<< "price  at"<<name<<"is now"<<price<<endl;
	}


};
class Subject{
	vector<ShopsOfObserver*> list;
public:
	Subject(){}
	void attach(ShopsOfObserver* Obj){
			list.push_back(Obj);
		}
	void deattahc(ShopsOfObserver* Obj){
			list.erase(remove(list.begin(),list.end(),Obj),list.end());
		}
	void notify(float price)
		{
			for(vector<ShopsOfObserver*>::iterator itr=list.begin();itr!=list.end();++itr)
			{
				if((*itr)!=0)
				{
					(*itr)->update(price);
				}
			}
		}
};


class Dummyproducts:public Subject{
public:
	void changeprice(float price)
	{
		notify(price);
	}

};


int main()
{
	Dummyproducts Product;
	//lets say we have 4 shops whose where price of the product getting updated by product owner
	ShopsOfObserver Shop1("ShopA");
	ShopsOfObserver Shop2("ShopB");
	Product.attach(&Shop1);
	Product.attach(&Shop2);
	Product.changeprice(23.0f);
	Product.deattahc(&Shop1);
	Product.changeprice(26.0f);
	return 0;

}
