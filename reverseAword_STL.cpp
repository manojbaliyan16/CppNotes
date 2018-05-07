/*#include<iostream>
#include <vector>

using namespace std;


int main(){

	string inp;
	std::vector<string> final;
	while(cin.get()!='\n'){
		cin>>inp;
		final.push_back(inp);
	}

	std::vector<string>::reverse_iterator it;

	for(it=final.rbegin();it!=final.rend();it++){
		cout<<*it<<'\t';
	}


	return 0;
}*/

#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stack>

	
#include <cstdlib> // system("Pause")

using namespace std;
int main()
{
    string inp;
    vector<string> final;

    while(cin.get()!='\n')
    {
     cin>>inp;
     final.push_back(inp);                    
                        
    }  

    vector<string>::reverse_iterator ii;
    
    for(ii=final.rbegin();ii!=final.rend();++ii)
     cout<<*ii<<"\t";
     
//system("PAUSE");
return 0;
    
}

