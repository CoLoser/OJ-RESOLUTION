#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 105;
int dp[MAXN][MAXN];
int a[MAXN][MAXN];
int dist[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int n, k;
int dfs(int x, int y) {
	int ans = 0;
	if(dp[x][y] == 0) {
		for(int i = 1; i <= k; ++i) {
			for(int j = 0; j < 4; ++j) {
				int dx = x + dist[j][0]*i, dy = y + dist[j][1]*i;

				if((dx <= n && dx >= 1 && dy <= n && dy >= 1)) {
					if(a[dx][dy] > a[x][y])
						ans = max(ans, dfs(dx, dy));
				}else continue;
			}
		}
		//cout << ans << endl;
		dp[x][y] = ans + a[x][y];
	}
	return dp[x][y];
}
int main() {
	while(cin >> n >> k && n != -1 && k != -1) {
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j) cin >> a[i][j];
		memset(dp, 0, sizeof(dp));
		printf("%d\n", dfs(1, 1));
	}
	return 0;
}