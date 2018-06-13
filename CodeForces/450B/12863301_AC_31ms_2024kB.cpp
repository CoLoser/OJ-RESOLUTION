#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;
ll ans[6];
const int MOD = 1000000007;

int main()
{
	ll x, y, n;
	while(cin >> x >> y >> n)
	{
		ans[0] = (x + MOD)% MOD;
		ans[1] = (y + MOD) % MOD;
		for(int i = 2; i < 6; ++i) ans[i] = (ans[i - 1] - ans[i - 2] + MOD) % MOD;
		cout << ans[(n - 1) % 6] << endl;
	}
} 