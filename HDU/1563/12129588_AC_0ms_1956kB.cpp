#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

map<int, int> m;

int main()
{
	int t;
	while(cin >> t && t)
	{
		int x;
		m.clear();
		for(int i = 0; i < t; ++i)
		{
			cin >> x;
			m[x]++;
		}
		for(map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
			if(it->second == 1)
			{
				cout << it->first <<endl;
				break;
		   }  
	}
	return 0;
}