#include <iostream>
#include <cstdio>
#include <cstring> 
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1000005;
int dp[MAXN];
int a[MAXN];
int MMAX[MAXN];

int main() {
	int n, m;

	while(cin >> m >> n) {
		memset(dp, 0, sizeof(dp));
		memset(MMAX, 0, sizeof(MMAX));
		
		for(int i = 0; i < n; ++i) cin >> a[i];
		
		int mmmax = -INF;
		for(int i = 0; i < m; ++i){
			mmmax = -INF;
			for(int j = i; j < n; ++j){
				dp[j] = max(dp[j - 1] + a[j], MMAX[j-1] + a[j]);
				MMAX[j-1] = mmmax;
				mmmax = max(mmmax, dp[j]);
			}
		}
		printf("%d\n", mmmax);
	}
}