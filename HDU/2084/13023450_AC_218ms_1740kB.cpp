#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 105;
int dp[MAXN][MAXN];


int main(){
	int c, n;
	cin >> c;
	while(c--){
		cin >> n;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j <= i; ++j) cin >> dp[i][j];
		for(int i = n - 2 ; i >= 0; --i)
			for(int j = 0; j <= i; ++j)
				dp[i][j] = dp[i][j] + max(dp[i+1][j+1], dp[i+1][j]);
		printf("%d\n", dp[0][0]);
	}
	return 0;
}
