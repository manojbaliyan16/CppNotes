#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
	std::vector<int> vect;
	for (int i = 0; i < 6; ++i)
	{
		vect.push_back(i);
	}
std::vector<int>::iterator it;
it=vect.begin();
while(it!=vect.end())
{
	std::cout << *it <<" ";
	it++;
}
std::cout<<std::endl;

	return 0;

}