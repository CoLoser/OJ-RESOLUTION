#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 30;
const int INF = 0x3f3f3f3f;
int f[MAXN];

struct _Edge {
	int from, to, val;
	_Edge() {
	}
	_Edge(int _from, int _to, int _val): from(_from), to(_to), val(_val) {
	}
};
_Edge edge[MAXN*(MAXN - 1)];
int n, cnt;

bool cmp(_Edge rhs1, _Edge rhs2) {
	return rhs1.val < rhs2.val;
}
int find(int x) {
	return f[x] == -1 ? x : find(f[x]);
}

int kruskal() {
	for(int i = 0; i < MAXN; ++i) f[i] = -1;
	int res = 0;
	int p = 0;
	for(int i = 0; i < cnt; ++i) {
		int x = find(edge[i].from);
		int y = find(edge[i].to);
		int val = edge[i].val;

		if(x != y) {
			f[x] = y;
			res += val;
			p ++;
		}
		if(p == n - 1) break;
	}
	if(p < n - 1) return -1;
	else return res;
}

void addEdge(int u, int v, int w) {
	edge[cnt].from = u;
	edge[cnt].to = v;
	edge[cnt].val = w;
	cnt ++;
}
int main() {
	int n;
	while(scanf("%d", &n) != EOF && n) {
		cnt = 0;
		char key01, key02;
		int dist, t;
		for(int i = 0; i < n - 1; ++i) {
			cin >> key01 >> t;
			for(int j = 0; j < t; ++j) {
				cin >> key02 >> dist;
				int u = key01 - 'A';
				int v = key02 - 'A';
				addEdge(u, v, dist);
			}
		}
		sort(edge, edge + cnt, cmp);
		int x = kruskal();
		printf("%d\n", x);
	}
	return 0;
}