/*
 * threads2.cpp
 *
 *  Created on: 03-Jul-2017
 *      Author: baliyan
 */
#include <iostream>
#include <vector>
#include <thread>
using namespace std;
//class ABC{
	void threadunction(int tid){
		cout<<"Thread id::"<<tid<<endl;
	}
//};


int main(){
	//ABC obj;
vector<thread> th;
int numberThreads=10;
for(int i=0;i<numberThreads;++i){
th.push_back(thread(threadunction,i));
}
for(auto & t:th){
	t.join();
}
}



