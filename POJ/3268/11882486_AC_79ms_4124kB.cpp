#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1005;
int cost[MAXN][MAXN];
int lowcost_from[MAXN];
int lowcost_to[MAXN];
int visit_from[MAXN];
int visit_to[MAXN];
int n, m, to;


void init(int beg)
{
	for(int i = 1; i <= n; ++i)
	{
		lowcost_from[i] = cost[beg][i];
		lowcost_to[i] = cost[i][beg];
		visit_from[i] = visit_to[i] = 0;
	}
	visit_from[beg] = 1;
	visit_to[beg] = 1;
}

void dijkstra(int beg)
{
	init(beg);
	int pre = beg;
	//从begin到个点
	for(int i = 1; i <= n; ++i)
	{
		int MIN = INF;
		for(int j = 1; j <= n; ++j)
		{
			if(!visit_from[j] && lowcost_from[pre] + cost[pre][j] < lowcost_from[j])
				lowcost_from[j] = lowcost_from[pre] + cost[pre][j];
		}
		for(int j = 1; j <= n; ++j)
		{
			if(!visit_from[j] && lowcost_from[j] < MIN)
			{
				MIN = lowcost_from[j];
				pre = j;
			}
		}
		if(MIN == INF) break;
		visit_from[pre] = 1;
	}

	pre = beg;

	//从各点到begin
	for(int i = 1; i <= n; ++i)
	{
		int MIN = INF;
		for(int j = 1; j <= n; ++j)
		{
			if(!visit_to[j] && lowcost_to[j] > lowcost_to[pre] + cost[j][pre])
				lowcost_to[j] = lowcost_to[pre] + cost[j][pre];
   		}
		for(int j = 1; j <= n; ++j)
		{
			if(!visit_to[j] && lowcost_to[j] < MIN)
			{
				MIN = lowcost_to[j];
				pre = j;
			}
		}
		if(MIN == INF) break;
		visit_to[pre] = 1;
	}
}

int main()
{
	int u, v, w;
	int cnt = 1;
	while(scanf("%d%d%d", &n, &m, &to) != EOF)
	{
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				cost[i][j] = (i == j) ? 0 : INF;
		for(int i = 1; i <= m; ++i)
		{
			scanf("%d%d%d", &u, &v, &w);
			if(cost[u][v] > w)
			{
				cost[u][v] = w;
			}
		}
		dijkstra(to);
  		int MAX = -1;
		for(int i = 1; i <= n; ++i)
			MAX = max(MAX, lowcost_from[i] + lowcost_to[i]);
			
		printf("%d\n", MAX);
	}
}