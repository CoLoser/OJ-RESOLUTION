#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*
	Name: lightOJ-1442
	Copyright: 区间dp
	Author: YancyKahn
	Date: 19/04/18 09:32
	Description:
*/

const int MAXN = 105;
int dp[MAXN][MAXN];		//dp[i][j]为从第i次到第j次所需的最少服装
int a[MAXN];

int main() {
	int t, n, kase=0;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n; ++i) dp[i][i] = 1;
		for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
		
		for(int i = 1; i < n; ++i) {
			for(int j = 1; i + j <= n; ++j) {
				dp[j][i+j] = dp[j+1][i+j]+1;
				for(int k = j + 1; k <= i+j; ++k) {
					if(a[j] == a[k])
						dp[j][i+j] = min(dp[j][i+j], dp[j][k-1] + dp[k+1][i+j]);
					}
			}
		}
		printf("Case %d: %d\n", ++kase, dp[1][n]);
	}
}