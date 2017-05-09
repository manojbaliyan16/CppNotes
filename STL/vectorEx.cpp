#include <iostream>
#include <vector>


int main(){
	using namespace std;
	vector<int> array;
	for (int i = 0; i < 6; ++i)
	{
		array.push_back(10-i);
	}
	for (int i = 0; i < 6; ++i)
	{
		cout<<array[i]<<endl;
	}
	
}