#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

struct _Node {
	int u, c;
	_Node() {
	}
	_Node(int _u, int _c) {
		u = _u;
		c = _c;
	}
	bool operator < (const _Node rhs) const {
		return c > rhs.c;
	}
};
struct _Edge {
	int v, cost;
	_Edge(int _v, int _cost) {
		v = _v;
		cost = _cost;
	}
};
const int MAXN = 1000005;
const int INF = 0x3f3f3f3f;
vector<_Edge> E[MAXN];
bool visit[MAXN];
int dist[MAXN];
int n, m;
void dijkstra(int beg) {
	memset(visit, 0, sizeof(visit));
	for(int i = 1; i <= m; ++i) dist[i] = INF;
	priority_queue<_Node> pq;
	while(!pq.empty()) pq.pop();
	pq.push(_Node(beg, 0));
	dist[beg] = 0;

	while(!pq.empty()) {
		_Node x = pq.top();
		pq.pop();
		int u = x.u;
		if(visit[u]) continue;
		visit[u] = 1;

		for(int i = 0; i < E[u].size(); ++i) {
			int v = E[u][i].v;
			int cost = E[u][i].cost;
			if(!visit[v] && dist[v] > dist[u] + cost) {
				dist[v] = dist[u] + cost;
				pq.push(_Node(v, dist[v]));
			}
		}
	}
}

void addEdge(int u, int v, int w) {
	E[u].push_back(_Edge(v, w));
	E[v].push_back(_Edge(u, w));
}
int main() {
	int u, v, w;
	while(cin >> n >> m) {
		for(int i = 0; i < n; ++i) {
			cin >> u >> v >> w;
			addEdge(u, v, w);
		}
		dijkstra(m);
		printf("%d\n", dist[1]);
	}
	return 0;
}