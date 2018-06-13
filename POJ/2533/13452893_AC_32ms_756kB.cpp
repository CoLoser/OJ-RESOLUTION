#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1005;
int a[MAXN];
int dp[MAXN];

int solove(int n) {
	int res = 0;
	for(int i = 0; i < n; ++i) {
		dp[i] = 1;
		for(int j = 0; j < i; ++j) {
			if(a[i] > a[j]) dp[i] = max(dp[j] + 1, dp[i]);
		}
		res = max(dp[i], res);
	}
	return res;
}
int main() {
	int n;
	while(cin >> n) {
		for(int i = 0; i < n; ++i) cin >> a[i];
		cout << solove(n) << endl;
	}
	return 0;
}