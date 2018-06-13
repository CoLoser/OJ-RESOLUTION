#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 10005;
const int INF = 0x3f3f3f3f;
int dp[MAXN]; 	//前i个的最长上升最序列和的最大值
int a[MAXN];

int solove(int n) {
	int res = -INF;
	for(int i = 1; i <= n; ++i) {
		int tmp = -INF;
		for(int j = 0; j <= i; ++j) {
			if(a[i] > a[j] && tmp < dp[j]) {
				tmp = dp[j];
			}
			dp[i] = tmp + a[i];
		}
		res = max(dp[i], res);
	}
	return res;
}
int main() {
	int  n;
	while(scanf("%d", &n) != EOF && n) {
		for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
		printf("%d\n", solove(n));
	}
}