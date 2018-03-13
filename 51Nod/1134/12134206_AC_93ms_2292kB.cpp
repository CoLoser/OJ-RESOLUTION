#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 50005;
const int INF = 0x3f3f3f3f;
int dp[MAXN], a[MAXN];

int solove(int t)
{
	for(int i = 0; i < t; ++i) *lower_bound(dp, dp + t, a[i]) = a[i];
	return lower_bound(dp, dp + t, INF) - dp;
}
int main()
{
	int t;
	while(cin >> t)
	{
		memset(dp, INF, sizeof(dp));
		for(int i = 0; i < t; ++i) cin >> a[i];
		cout << solove(t) <<endl;
	}
	return 0;
}