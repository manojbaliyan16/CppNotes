/*
 * Threads1.cpp
 *
 *  Created on: 03-Jul-2017
 *      Author: baliyan
 */

#include <iostream>
#include <thread>
using namespace std;
static const int number=10;

class AC{
public:
	void call_from_thread(int tid) {
         cout << "Thread Id:: "<< tid <<endl;
     }
};
int main()
{

	thread t[number];
	for(int i=0;i<10;i++)
	thread(&AC::call_from_thread,AC());
	cout<<"launched from main Thead"<<endl;
	for(int i=0;i<10;i++){
		t[i].join();
	}


	return 0;
}

