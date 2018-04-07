#include <iostream>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
int bit[11];
int dp[60000][12];
int key[12][12];
int state[60000][12];

void getState() {
	for(int i = 0; i < bit[10]; ++i) {
		int b = i;
		for(int j = 0; j < 10; ++j) {
			state[i][j] = b%3;
			b /= 3;
		}
	}
}
void getbit() {
	bit[0] = 1;
	for(int i = 1; i < 11; ++i) bit[i] = bit[i - 1]*3;
	//for(int i = 0; i < 11; ++i) printf("%d\n", bit[i]);
}

int main() {
	int n, m, ans;
	getbit();
	getState();
	while(cin >> n >> m) {
		ans = INF;
		memset(key, INF, sizeof(key));
		memset(dp, INF, sizeof(dp));
		int a, b, v;
		for(int i = 0; i < m; ++i) {
			cin >> a >> b >> v;
			if(key[a-1][b-1] > v) {
				key[a-1][b-1] = key[b-1][a-1] = v;
			}
		}

		//开始搜索位置
		for(int i = 0; i < n; ++i) dp[bit[i]][i] = 0;

		bool flag = 1;
		for(int i = 0; i < bit[n]; ++i) {	//状态
			flag = 1;
			for(int j = 0; j < n; ++j) {		//城市终点
				if(state[i][j] == 0) flag = 0;		//有城市未遍历
				if(dp[i][j] == INF) continue;

				for(int k = 0; k < n; ++k) {		//城市起点

					if(j == k || state[i][k] >= 2 || key[j][k] == INF) continue;
					int next = i + bit[k];
					dp[next][k] = min(dp[i][j] + key[j][k], dp[next][k]);
				}
			}
			
			if(flag == 1) {
				for(int j = 0; j < n; ++j) {
					ans = min(ans, dp[i][j]);
				}
			}
		}
		if(ans == INF) ans = -1;
		printf("%d\n", ans);
	}
	return 0;
}