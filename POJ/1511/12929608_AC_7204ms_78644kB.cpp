#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
struct _Node {
	int v;
	ll c;
	_Node() {
	}
	_Node(int _v, ll _c): v(_v), c(_c) {
	}
	bool operator < (const _Node &rhs) const {
		return c > rhs.c;
	}
};
struct _Edge {
	int u;
	ll cost;
	_Edge() {
	}
	_Edge(int _u, ll _cost): u(_u), cost(_cost) {
	}
};
const ll INF = 0x3f3f3f3f;
const int MAXN = 1000005;
vector<_Edge> E[MAXN];
int n, m;
ll lowcost[MAXN];
int visit[MAXN];
int tmp[MAXN][3];

ll dijkstra(int beg) {
	memset(lowcost, INF, sizeof(lowcost));
	memset(visit, 0, sizeof(visit));
	lowcost[beg] = 0;
	priority_queue<_Node> q;
	q.push(_Node(beg, 0));
	while(!q.empty()) {
		_Node x = q.top();
		q.pop();
		if(visit[x.v]) continue;
		visit[x.v] = 1;
		for(int j = 0; j < E[x.v].size(); ++j) {
			int u = x.v;
			int v = E[u][j].u;
			ll cost = E[u][j].cost;
			if(!visit[v] && lowcost[v] > lowcost[u] + cost) {
				lowcost[v] = lowcost[u] + cost;
				q.push(_Node(v, lowcost[v]));
			}
		}
	}

	ll res = 0;
	for(int i = 1; i <= n; ++i) res += lowcost[i];
	//cout << res << endl;
	return res;
}
void addEdge(int u, int v, ll cost) {
	E[u].push_back(_Edge(v, cost));
}

void init(){
	for(int i = 1; i <= n; ++i) E[i].clear();
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &m);
		init();
		int u, v;
		ll cost;
		for(int i = 0; i < m; ++i) {
			scanf("%d%d%lld", &u, &v, &cost);
			tmp[i][0] = u;
			tmp[i][1] = v;
			tmp[i][2] = cost;
			addEdge(u, v, cost);
		}
		ll res = dijkstra(1);
		init();
		for(int i = 0; i < m; ++i) {
			addEdge(tmp[i][1], tmp[i][0], tmp[i][2]);
		}
		res += dijkstra(1);
		cout << res << endl;
	}
	return 0;
}