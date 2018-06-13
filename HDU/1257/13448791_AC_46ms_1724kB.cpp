#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 10000;
int dp[MAXN];
int a[MAXN];
int n;
int solove() {
	for(int i = 0; i < n; ++i) {
		dp[i] = 1;
		for(int j = 0; j <= i; ++j) {
			if(a[j] < a[i]) dp[i] = max(dp[j] + 1, dp[i]);
		}
	}
	int ans = -1;
	for(int i = 0; i < n; ++i)ans = max(dp[i], ans);
	return ans;
}
int main() {

	while(cin >> n) {
		for(int i = 0; i < n; ++i) cin >> a[i];
		cout << solove() << endl;
	}
}