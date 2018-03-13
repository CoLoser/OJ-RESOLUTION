#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 30005;

vector<int> per[maxn];
int out[maxn];
int n, m;
int ans[maxn];

void topo()
{
	int cnt = n;
	priority_queue<int> pq;
	for(int i = 1; i <= n; ++i)
		if(out[i] == 0) pq.push(i);
	while(!pq.empty())
	{
		int x = pq.top(); pq.pop();
		ans[cnt--] = x;
		for(int i = 0; i < per[x].size(); ++i) if(--out[per[x][i]] == 0) pq.push(per[x][i]);
	}
	for(int i = 1; i <= n; ++i)
			printf("%d%c", ans[i], i == n ? '\n' : ' ');
}

void init()
{
	memset(out, 0, sizeof(out));
	for(int i = 1; i <= n; ++i) per[i].clear();
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		init();
		scanf("%d%d", &n, &m);
		int a, b;
		while(m--)
		{
			scanf("%d%d", &a, &b);
			out[a]++;
			per[b].push_back(a);
		}
		topo();
	}
	return 0;
}