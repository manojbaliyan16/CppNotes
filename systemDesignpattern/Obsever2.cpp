/*
 * Obsever2.cpp
 *
 *  Created on: 08-Jun-2017
 *      Author: baliyan
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>



using namespace std;

class IObserver
{
public:
    virtual void Update(float price) = 0;
};
class Shop : IObserver
{
    //Name of the Shop
    std::string name;
    float price;
public:
    Shop(std::string n);
    void Update(float price);
};
Shop::Shop(std::string name)
{
    this->name = name;
}

void Shop::Update(float price)
{
    this->price = price;

    //Lets print on console just to test the working
    std::cout << "Price at "<< name << " is now "<< price << "\n";
}
class ASubject
{
    //Lets keep a track of all the shops we have observing
    std::vector<Shop*> list;

public:
    void Attach(Shop *product);
    void Detach(Shop *product);
    void Notify(float price);
};
void ASubject::Attach(Shop *shop)
{
    list.push_back(shop);
}
void ASubject::Detach(Shop *shop)
{
    list.erase(std::remove(list.begin(), list.end(), shop), list.end());
}

void ASubject::Notify(float price)
{
    for(vector<Shop*>::const_iterator iter = list.begin(); iter != list.end(); ++iter)
    {
        if(*iter != 0)
        {
            (*iter)->Update(price);
        }
    }
}
class DummyProduct : public ASubject
{
public:
    void ChangePrice(float price);
};
void DummyProduct::ChangePrice(float price)
{
    Notify(price);
}
int main(int argc, char* argv[])
{
    DummyProduct product;

    // We have four shops wanting to keep updated price set by product owner
    Shop shop1("Shop 1");
    Shop shop2("Shop 2");

    product.Attach(&shop1);
    product.Attach(&shop2);

    //Now lets try changing the products price, this should update the shops automatically
    product.ChangePrice(23.0f);

    //Now shop2 is not interested in new prices so they unsubscribe
    product.Detach(&shop2);

    //Now lets try changing the products price again
    product.ChangePrice(26.0f);


    return 0;
}


