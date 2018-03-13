#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 105;
const int INF = 0x3f3f3f;

int map[MAXN][MAXN];
int visit[MAXN];
int dist[MAXN];

void dijkstra(int n)
{
	memset(visit, 0, sizeof(visit));
	
	for(int i = 1; i <= n; ++i) dist[i] = ((i == 1) ? 0 : INF);
	
	for(int i = 1; i <= n; ++i)
	{
		int x, MIN = INF;
		for(int y = 1; y <= n; ++y)
			if(!visit[y] && dist[y] <= MIN) MIN = dist[x = y];
		visit[x] = 1;
		for(int y = 1; y <= n; ++y) dist[y] = min(dist[y], dist[x] + map[x][y]);
	}
}

void init()
{
	for(int i = 0; i < MAXN; ++i)
		for(int j = 0; j < MAXN; ++j)
			map[i][j] = ((i == j) ? 0 : INF);
}

char key[10];
int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		init();
		
		for(int i = 2; i <= n; ++i)
		{
			int ans = 0;
			for(int j = 1; j < i; ++j)
			{
				cin >> key;
				ans = 0;
				if(strcmp(key, "x") == 0) ans = INF;
				else{
					for(int k = 0; k < strlen(key); ++k)
						ans = ans*10 + key[k] - '0';
				}
				map[i][j] = ans;
				map[j][i] = ans;
			}
		}
		
		dijkstra(n);
		
		int ans = -1;
		for(int i = 1; i <= n; ++i)
			ans = max(ans, dist[i]);
		printf("%d\n", ans);
		
	}
}