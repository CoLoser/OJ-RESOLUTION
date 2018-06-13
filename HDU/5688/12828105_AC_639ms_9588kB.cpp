#include <iostream>
#include <cstring>
#include <map>
#include <algorithm> 
using namespace std;

int main()
{
	map<string, int> strmap;
	string str;
	int t;
	
	while(cin >> t)
	{
		for(int i = 0; i < t; ++i)
		{
			cin >> str;
			sort(str.begin(), str.end());
			cout << strmap[str] <<endl;
			strmap[str]++;
		}
	}
	return 0;
 } 