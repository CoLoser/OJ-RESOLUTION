#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

map<string, int> m;
int main()
{
	int t;
	string str; 
	string ans;
	int MAX;
	while(cin >> t && t)
	{
		MAX = -1;
		m.clear();
		for(int i = 0; i < t; ++i) cin >> str, m[str]++;
 		for(map<string, int>::iterator it = m.begin(); it != m.end(); ++it)
 		{
 			if(it->second > MAX)
 			{
 				MAX = it->second;
 				ans = it->first;
			 }
		}
		cout << ans <<endl;
 		
	}	
} 