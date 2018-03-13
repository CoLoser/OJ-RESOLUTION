#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 500000;
int hashMap[MAXN<<1|1];

int main()
{
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF)
	{
		int i;
		memset(hashMap, 0, sizeof(hashMap));
		int key = 0;
		for(i = 0; i < n; ++i)
		{
			scanf("%d", &key);
			hashMap[MAXN + key] = 1;
		}
		
		int flag = 0;
		for(i = MAXN<<1; i >= 0 && m > 0; i--)
		{
			if(!hashMap[i])continue;
			if(flag)cout << ' ' << i - MAXN;
			else cout << i - MAXN;
			flag = 1;
			m--;
		}
		cout << endl;
	}
	return 0;
}