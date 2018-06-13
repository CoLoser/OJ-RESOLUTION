#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 2005;
int dp[MAXN][MAXN], a[MAXN];	//dp[i][j] = max(dp[i-1][j] + a[i]*(i+j), dp[i][j-1] + a[n-j-1]*(i + j))	// 取左边或者右边

int main() {
	int n;
	while(cin >> n) {
		for(int i = 1; i <= n; ++i) cin >> a[i];

		int res = 0;
		for(int i = 0; i <= n; ++i)
			for(int j = 0; i + j <= n; ++j) {
				if(i > 0 && j > 0) {
					dp[i][j] = max(dp[i-1][j] + a[i]*(i + j), dp[i][j - 1] + a[n - j + 1]*(i + j));
				} else if(i > 0) {
					dp[i][j] = dp[i-1][j] + a[i]*(i + j);
				} else if(j > 0) {
					dp[i][j] = dp[i][j - 1] + a[n - j + 1]* (i + j);
				}
				res = max(res, dp[i][j]);
				//cout << i<< " " << j << " " << dp[i][j] << endl;
			}
		printf("%d\n", res);
	}
}