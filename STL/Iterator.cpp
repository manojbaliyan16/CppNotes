#include <iostream>
#include <vector>
#include <list>

int main(int argc, char const *argv[])
{
	std::list<int> li;
	for (int i = 0; i < 6; ++i)
	{
		li.push_back(i);
	}
std::list<int>::iterator it;
it=li.begin();
while(it!=li.end())
{
	std::cout << *it <<" ";
	it++;
}
std::cout<<std::endl;

	return 0;

}