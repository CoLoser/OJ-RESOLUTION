#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1005;
const int INF = 0x3f3f3f3f;
int cost[MAXN][MAXN];
int visit[MAXN];
int lowcost[MAXN];
int n, m;
void init() {
	for(int i = 0; i < MAXN; ++i)
		for(int j = 0; j < MAXN; ++j) cost[i][j] = 0;
}

void dijkstra(int beg) {
	memset(visit, 0, sizeof(visit));
	for(int i = 1; i <= n; ++i) lowcost[i] = cost[beg][i];
	visit[beg] = 1;
	lowcost[beg] = 0;
	int pre = beg;

	for(int i = 1; i <= n; ++i) {
		int MAX = -1;
		for(int j = 1; j <= n; ++j) {
			if(!visit[j] && min(lowcost[pre], cost[pre][j]) > lowcost[j]) lowcost[j] = min(lowcost[pre], cost[pre][j]);
		}

		for(int j = 1; j <= n; ++j) {
			if(!visit[j] && MAX < lowcost[j]) {
				MAX = lowcost[j];
				pre = j;
			}
		}
		visit[pre] = 1;
	}
}
int main() {
	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i) {
		init();
		cin >> n >> m;

		for(int j = 1; j <= m; ++j) {
			int u, v, w;
			cin >> u >> v >> w;
			if(cost[u][v] < w) {
				cost[u][v] = cost[v][u] = w;
			}
		}
		dijkstra(1);
		printf("Scenario #%d:\n", i);
		printf("%d\n\n", lowcost[n]);
	}
	return 0;
}