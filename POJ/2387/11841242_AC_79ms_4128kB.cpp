#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
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
		int MIN = INF;
		for(int j = 1; j <= n; ++j)
		{
			if(!visit[j] && lowcost[pre] + cost[pre][j] < lowcost[j])
			{
				lowcost[j] = lowcost[pre] + cost[pre][j];
			}
		}
		for(int j = 1; j <= n; ++j)
		{
			if(!visit[j] && lowcost[j] < MIN)
			{
				MIN = lowcost[j];
				pre = j;
			}
		}
		visit[pre] = 1;
	}
}

void init()
{
	for(int i = 0; i < MAXN; ++i)
		for(int j = 0; j < MAXN; ++j)
			cost[i][j] = (i == j) ? 0 : INF;
}

int main()
{
	int u, v, w;
	while(scanf("%d%d", &m, &n) != EOF)
	{
		init();
		for(int i = 1; i <= m; ++i)
		{
			scanf("%d%d%d", &u, &v, &w);
			if(cost[u][v] > w)
			{
				cost[u][v] = w;
				cost[v][u] = w;
			}
		}
		dijkstra(1);
		printf("%d\n", lowcost[n]);
	}
	return 0;
}