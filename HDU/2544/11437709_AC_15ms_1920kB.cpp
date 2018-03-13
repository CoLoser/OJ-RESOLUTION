#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 105;
const int INF = 0x3ffffff;

int dist[maxn];
int edges[maxn][maxn];
bool visit[maxn];
int n, m;

void init()
{
	memset(visit, 0, sizeof(visit));
	for(int i = 1; i <= n; ++i)
		dist[i] = (i==1 ?0:INF);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			edges[i][j] = (i == j?0:INF);
}
void dijkstra()
{
	for(int i = 1; i <= n; ++i)
	{
		int x;
		int MIN = INF;
		for(int y = 1; y <= n; ++y)
			if(!visit[y] && dist[y] <= MIN) MIN = dist[x=y];
		visit[x] = 1;
		for(int y = 1; y <= n; ++y)
			dist[y] = min(dist[y], dist[x] + edges[x][y]);
	}
}
int main()
{
	while(scanf("%d%d", &n, &m) != EOF)
	{
		if(m == 0 && n == 0) break;
		init();
		int a, b, c;
		for(int i = 0; i < m; ++i)
		{
			scanf("%d%d%d", &a, &b, &c);
			if(edges[a][b] > c) edges[a][b] = edges[b][a] = c;
		}
		
		dijkstra();
		printf("%d\n", dist[n]);
	}
	return 0;
}