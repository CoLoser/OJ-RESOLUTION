#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

const int MAXN = 40;
map<string, int> money;
struct _Edge {
	int u, v;
	double rate;
	_Edge() {
	}
	_Edge(int _u, int _v, double _rate) {
		u = _u;
		v = _v;
		rate = _rate;
	}
};
vector<_Edge> E;
double dist[MAXN];
int n, m;
bool bellman_ford(int beg) {
	memset(dist, 0, sizeof(dist));
	dist[beg] = 1;

	for(int i = 1; i < n; ++i) {
		for(int j = 0; j < E.size(); ++j) {
			int u = E[j].u;
			int v = E[j].v;
			double rate = E[j].rate;
			if(dist[v] < rate * dist[u]) {
				dist[v] = rate * dist[u];
			}
		}
	}

	for(int j = 0; j < E.size(); ++j)
		if(E[j].rate * dist[E[j].u] > dist[E[j].v]) return false;
	return true;
}
int main() {

	string s1, s2, s;
	double rate;
	int cnt = 0;
	while(scanf("%d", &n) != EOF && n) {
		money.clear();
		E.clear();
		for(int i = 1; i <= n; ++i) {
			cin >> s;
			money[s] = i;
		}
		cin >> m;
		for(int i = 0; i < m; ++i) {
			cin >> s1 >> rate >> s2;
			E.push_back(_Edge(money[s1], money[s2], rate));
		}
		printf("Case %d: ", ++cnt);
		for(int i = 1; i <= n; ++i)
			if(!bellman_ford(i)) {
				printf("Yes\n");
				break;
			} else if(i == n) printf("No\n");
	}
	return 0;
}