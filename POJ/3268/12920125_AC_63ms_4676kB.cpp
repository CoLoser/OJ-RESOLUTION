#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1005;
const int MAXM = 100005;
int lowcost_from[MAXN];
int lowcost_to[MAXN];
int cost[MAXN][MAXN];
int visit[MAXN];
const int INF = 0x3f3f3f3f;
int n, m, end;

void dijkstra(int beg) {
	int pre = beg;
	memset(visit, 0, sizeof(visit));
	visit[beg] = 1;
	for(int i = 1; i <= n; ++i) lowcost_from[i] = cost[beg][i];
	lowcost_from[beg] = 0;
	for(int i = 1; i <= n; ++i) {
		int MIN = INF;

		for(int j = 1; j <= n; ++j) {
			if(!visit[j] && lowcost_from[pre] + cost[pre][j] < lowcost_from[j]) lowcost_from[j] = cost[pre][j] + lowcost_from[pre];
		}
		for(int j = 1; j <= n; ++j) {
			if(!visit[j] && MIN > lowcost_from[j]) {
				MIN = lowcost_from[j];
				pre = j;
			}
		}
		visit[pre] = 1;
	}

	pre = beg;
	memset(visit, 0, sizeof(visit));
	visit[beg] = 1;
	for(int i = 1; i <= n; ++i) lowcost_to[i] = cost[i][beg];
	lowcost_to[beg] = 0;

	for(int i = 1; i <= n; ++i) {
		int MIN = INF;

		for(int j = 1; j <= n; ++j) {
			if(!visit[j] && lowcost_to[pre] + cost[j][pre] < lowcost_to[j]) lowcost_to[j] = cost[j][pre] + lowcost_to[pre];
		}
		for(int j = 1; j <= n; ++j) {
			if(!visit[j] && MIN > lowcost_to[j]) {
				MIN = lowcost_to[j];
				pre = j;
			}
		}
		visit[pre] = 1;
	}

}

void init() {
	for(int i = 0; i < MAXN; ++i)
		for(int j = 0; j < MAXN; ++j) cost[i][j] = (i == j) ? 0 : INF;
}
int main() {

	while(scanf("%d%d%d", &n, &m, &end) != EOF) {
		init();
		int u, v, w;
		for(int i = 0; i < m; ++i) {
			scanf("%d%d%d", &u, &v, &w);
			if(cost[u][v] > w) {
				cost[u][v] = w;
			}
		}
		dijkstra(end);
		int MAX = -1;
		for(int i = 1; i <= n; ++i)
			MAX = max(MAX, lowcost_from[i] + lowcost_to[i]);
		printf("%d\n", MAX);
	}
}