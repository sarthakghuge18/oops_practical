//map c7

/*
Write a program in C++ to use map associative container. 
The keys will be the names of states and the values will be the populations of the states. 
When the program runs, the user is prompted to type the name of a state. 
The program then looks in the map, using the state name as an index and returns the population of the state.
*/

#include<iostream>
#include<map>
using namespace std;
int main()
{
	map<string,int>state;		//state is object
	state.insert(pair<string,int>("maharashtra",9087879));  		//insert a pair of string and int value 
	state.insert(pair<string,int>("goa",8087879));
	state.insert(pair<string,int>("karnataka",7087879));
	state.insert(pair<string,int>("jammu",6087879));
	state.insert(pair<string,int>("odisha",5087879));
	state.insert(pair<string,int>("himachal",4087879));
	state.insert(pair<string,int>("haryana",3087879));
	string search;
	cout<<"enter the state to be search : "<<endl;
	cin>>search;
	map<string,int>::iterator i;
	int flag=0;
	for(i=state.begin();i!=state.end();i++)
	{
		if(search==i->first)
		{
			flag++;
			cout<<"the population of "<<i->first<<"="<<i->second;
		}
	}
	if(flag==0)
	{
		cout<<"state not found ";
	}
	return 0;
}

