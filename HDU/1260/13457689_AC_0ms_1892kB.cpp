#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 2005;
int a[MAXN], b[MAXN], dp[MAXN];		//dp[i]表示到第i个人时花费的最少时间
//dp[i] = min(dp[i-1]+a[i], dp[i-2]+b[i]) 单独买和加前面的人买的最小值
int main() {
	int t, n;
	scanf("%d",&t);
	while(t--) {
		scanf("%d", &n);
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
		for(int i = 1; i < n; ++i) scanf("%d", &b[i]);
		dp[0]=a[0];
		for(int i = 1; i < n; ++i)
			dp[i] = min(dp[i-1]+a[i], dp[i-2]+b[i]);

		int x = dp[n-1];
		int h = x/(60*60) + 8;
		x %= (60*60);
		int m = x/60;
		x%= 60;
		int s = x;
		printf("%02d:%02d:%02d %s\n", h, m, s, h >= 12 ? "pm" : "am");
	}
	return 0;
}