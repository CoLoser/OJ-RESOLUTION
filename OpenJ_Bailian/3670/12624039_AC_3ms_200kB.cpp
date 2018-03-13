#include <iostream>
#include <cstdio>
#include <limits.h>
#include <cstring>
using namespace std;

int MAX[6], MIN[6];
int main()
{
	for(int i = 0; i < 6; ++i)
	{
		MAX[i] = INT_MIN;
		MIN[i] = INT_MAX;
	}
	int t;
	for(int i = 1; i < 6; ++i)
	{
		for(int j = 1; j < 6; ++j)
		{
			cin >> t;
			
			MAX[i] = max(MAX[i], t);
			MIN[j] = min(MIN[j], t);
		}
	}
	
	bool flag = true;
	for(int i = 1; i < 6; ++i)
	{
		for(int j = 1; j < 6; ++j)
		{
			//cout << MAX[i] <<"  " << MIN[j] <<endl;
			if(MAX[i] == MIN[j])
			{
				printf("%d %d %d\n", i, j, MAX[i]);
				flag = false;
			}
		}
	}
	
	if(flag) cout << "not found\n" <<endl;
	
	return 0;
 } 