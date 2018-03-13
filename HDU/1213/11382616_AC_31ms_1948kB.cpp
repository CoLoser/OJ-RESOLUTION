#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 1005;
int per[maxn];
int visit[maxn];

void init()
{
	memset(visit, 0, sizeof(visit));
	for(int i = 0; i < maxn; ++i)
		per[i] = i;
}
int find(int p)
{
	return p == per[p] ? p : find(per[p]);
}

void Union(int a, int b)
{
	int x = find(a);
	int y = find(b);
	
	if(x != y) per[y] = x;
}
int n, m;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		init();
		cin >> n >> m;
		while(m--)
		{
			int a, b;
			cin >> a >>b;
			Union(a, b);
		}
		
		int ans = 0;
		for(int i = 1; i <= n; ++i)
		{
			int x = find(i);
			visit[x] = 1;
			if(visit[i]) ans ++;
		}
		cout << ans <<endl;
	}
}