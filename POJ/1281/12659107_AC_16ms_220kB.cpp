#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

vector<int> list01, list02;
multiset<int> mset;


void PrintSet()
{
	for(multiset<int>::iterator it = mset.begin(); it != mset.end(); ++it) 
		cout << *it << "   ";
	cout << endl;
}
void add()
{
	int x;
	cin >> x;
	mset.insert(x);
}
void rm(int policy)
{
	//PrintSet();
	if(mset.empty()) cout << "-1" << endl;
	else if(policy == 1)
	{
		multiset<int>::iterator it01 = mset.begin();
		list01.push_back(*it01);
		mset.erase(*it01);	
	}else if(policy == 2)
	{
		multiset<int>::reverse_iterator it01 = mset.rbegin();
		//multiset<int>::iterator it01 = mset.end();
		list01.push_back(*(it01));
		mset.erase(*(it01));
	}
}
int main()
{
	int MAXCOST, rlen, a;
	char option;
	
	while(cin >> MAXCOST >> rlen)
	{
		mset.clear();
		list01.clear();
		list02.clear();
		
		for(int i = 0; i < rlen; ++i)
		{
			cin >> a;
			list02.push_back(a);
		}
		
		int policy = 1;
		
		while(cin >> option && option != 'e')
		{
			if(option == 'a') add();
			else if(option == 'r') rm(policy);
			else cin >> policy;
		}
		
		for(int i = 0; i < rlen; ++i)
			cout << list01[list02[i] - 1] << endl;
		cout << endl;
	}
	return 0;
}