#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
/*
	Name: HDU-1176
	Copyright:
	Author: YancyKahn
	Date: 13/04/18 10:06
	Description:数字三角形 
*/

const int MAXN = 100005;
const int INF = 0x3f3f3f3f;
int dp[MAXN][13];
int a[MAXN][13];

int main() {
	int n;
	while(scanf("%d", &n) != EOF && n) {
		memset(a, 0, sizeof(a));
		memset(dp, 0, sizeof(dp));
		int p, t;
		int maxtime = 0;
		for(int i = 0; i < n; ++i) {
			scanf("%d%d", &p, &t);
			a[t][p]++;
			maxtime = max(maxtime, t);
		}
//		for(int i = 0; i <= maxtime; ++i) {
//			for(int j = 0; j < 11; ++j) {
//				printf("%d ", a[i][j]);
//			}
//			printf("\n");
//		}
		for(int i = 0; i < 11; ++i) dp[maxtime-1][i] = a[maxtime-1][i];
		
		for(int i = maxtime-1; i >= 0; --i) {
			for(int j = 0; j < 11; ++j) {
				int left = dp[i+1][j-1] + a[i+1][j-1];
				int mid = dp[i+1][j] + a[i+1][j];
				int right = dp[i+1][j+1] + a[i+1][j+1];
				dp[i][j] = max(left, max(mid, right));
			}
		}
//		for(int i = 0; i < maxtime; ++i) {
//			for(int j = 0; j < 11; ++j) {
//				printf("%d ", dp[i][j]);
//			}
//			printf("\n");
//		}
		printf("%d\n", dp[0][5]);
	}
}