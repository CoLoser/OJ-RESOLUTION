#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN = 1005;
int cost[MAXN][MAXN];
int lowcost[MAXN];
int visit[MAXN];
int n, m;

void dijkstra(int beg)
{
	memset(visit, 0, sizeof(visit));
	for(int i = 1; i <= n; ++i) lowcost[i] = cost[beg][i];
	visit[beg] = 1;
	lowcost[beg] = 0;
	int pre = beg;
	for(int i = 1; i <= n; ++i)
	{
		int MAX = -1;
		for(int j = 1; j <= n; ++j)
		{
			if(!visit[j] && lowcost[j] < min(lowcost[pre], cost[pre][j]))
			{
				lowcost[j] = min(lowcost[pre], cost[pre][j]);
			}
		}
		for(int j = 1; j <= n; ++j)
		{
			if(!visit[j] && lowcost[j] > MAX)
			{
				MAX = lowcost[j];
				pre = j;
			}
		}
		visit[pre] = 1;
	}
}

void init()
{
	memset(visit, 0, sizeof(visit));
	for(int i = 0; i < MAXN; ++i)
		for(int j = 0; j < MAXN; ++j)
			cost[i][j] = 0;
}
int main()
{
	int t, u, v;
	int w;
	int cnt = 1;
	scanf("%d", &t);
	while(t--)
	{
		init();
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= m; ++i)
		{
			scanf("%d%d%intd", &u, &v, &w);
			if(cost[u][v] < w)
			{
				cost[u][v] = w;
				cost[v][u] = w;
			}
		}
		dijkstra(1);
		printf("Scenario #%d:\n", cnt++);
		printf("%d\n\n", lowcost[n]);
	}
}