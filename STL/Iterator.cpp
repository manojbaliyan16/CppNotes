#include <iostream>
#include <vector>
#include <list>

int main(int argc, char const *argv[])
{
	using namespace std;
	list<int> li;
	for (int i = 0; i < 3; ++i)
	{
		li.push_front(i);
	}
list<int>::iterator it;
it=li.begin();
while(it!=li.end())
{
	cout << *it <<" ";
	it++;
}
cout<<std::endl;
cout<<"Insert from End"<<endl;

for (int i = 3; i < 6; ++i)
{
	li.push_back(i+2);
}
for (int i = 3; i < 6; ++i)
{
	li.push_front(i+2);
}
cout<< *it <<endl;
	return 0;

}