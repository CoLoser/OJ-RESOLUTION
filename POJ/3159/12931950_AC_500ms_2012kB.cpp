#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct _Edge {
	int next, to, val;
	_Edge() {
	}
	_Edge(int _next, int _to, int _val): next(_next), to(_to), val(_val) {
	}
};
const int MAXN = 30005;
const int MAXE = 150005;
const int INF = 0x3f3f3f3f;
int visit[MAXN];
int dist[MAXN];
_Edge edge[MAXE];
int head[MAXN]; //每个节点的头指针
int top, tol;
int n, m;
int q[MAXN];

void spfa(int beg) {
	top = 0;
	for(int i = 1; i <= n; ++i) {
		if(i == beg) {
			visit[beg] = 1;
			dist[beg] = 0;
			q[top++] = beg;
		} else {
			visit[i] = 0;
			dist[i] = INF;
		}
	}

	while(top != 0) {
		int u = q[--top];
		visit[u] = 0;

		for(int i = head[u]; i != -1; i = edge[i].next) {
			int v = edge[i].to;
			int cost = edge[i].val;
			//cout << cost << endl;
			if(dist[v] > dist[u] + cost) {

				dist[v] = dist[u] + cost;
				if(!visit[v]) {
					visit[v] = 1;
					q[top++] = v;
				}
			}
		}
	}
}

void addEdge(int a, int b, int c) {
	edge[tol].to = b;
	edge[tol].val = c;
	edge[tol].next = head[a];
	head[a] = tol++;
}
int main() {
	int a, b, c;
	while(scanf("%d%d", &n, &m) != EOF) {
		tol = 0;
		memset(head, -1, sizeof(head));
		for(int i = 0; i < m; ++i) {
			scanf("%d%d%d", &a, &b, &c);
			addEdge(a, b, c);
		}
		spfa(1);
		printf("%d\n", dist[n]);
	}
}