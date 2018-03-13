#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

map<int, int> m;

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		int key = 0;
		m.clear();
		for(int i = 0; i < n; ++i)
		{
			scanf("%d", &key);
			m[key]++;
		}
		int MAX = -1;
		int idx;
		for(map<int, int>::iterator it = m.begin(); it != m.end(); it++)
		{
			if(it->second > MAX)
			{
				MAX = it->second;
				idx = it->first;
			}
		}
		printf("%d\n", idx);
	}
	return 0;
}