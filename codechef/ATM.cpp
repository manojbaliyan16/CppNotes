#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int WithdrwalAmnt;
	double initialAmnt;
	cin>>WithdrwalAmnt>>initialAmnt;
		if((WithdrwalAmnt<initialAmnt-0.5) && (WithdrwalAmnt%5==0))
		{
			initialAmnt=initialAmnt-WithdrwalAmnt-0.50;
			cout<<fixed<<setprecision(2)<<initialAmnt;
		}
		else
		{
		
			cout<<fixed<<setprecision(2)<<initialAmnt;
		}
		
	
	
}
/*
#include<iostream>
using namespace std;
main()
{
 int x;
 float y;
 cin>>x>>y;
 if(x%5==0&&(x+0.50)<y)
 cout<<y-0.50-x;
 else
 cout<<y;
 } */