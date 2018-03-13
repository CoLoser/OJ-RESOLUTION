#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 105;
int G[MAXN][MAXN];
int n, m;

void floyd() {
	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				G[i][j] = G[i][j] || (G[i][k] && G[k][j]);
}
int main() {
	while(scanf("%d%d", &n, &m) != EOF) {
		memset(G, 0, sizeof(G));
		int u, v;
		for(int i = 0; i < m; ++i) {
			scanf("%d%d", &u, &v);
			G[u][v] = 1;
		}
		floyd();
		int res = 0;
		for(int i = 1; i <= n; ++i) {
			int ans = 0;
			for(int j = 1; j <= n; ++j) {
				if(i == j) continue;
				if(G[i][j] || G[j][i]) ans ++;
			}
			if(ans == n - 1) res ++;
		}
		printf("%d\n", res);
	}
	return 0;
}