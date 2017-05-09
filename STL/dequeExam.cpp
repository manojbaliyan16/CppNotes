#include <iostream>
#include <deque>


int main(int argc, char const *argv[])
{
	using namespace std;		
	int count=6;
	deque<int> queue;
	for (int i = 0; i < 3; ++i)
	{
		queue.push_back(10-i);
	}
	for (int i = 0; i < 3; ++i)
	{
		cout<<queue[i]<<endl;
	}
	cout<<"*************"<<endl;
	for (int i = 3; i < count; ++i)
	{
		queue.push_front(1+i);
	}
	for (int i = 0; i < count; ++i)
	{
		cout<<queue[i]<<endl;
	}
	return 0;
}