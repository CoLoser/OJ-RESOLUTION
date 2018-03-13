#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;
const ll INF = 1000000005;
const int MAXN = 50005;
ll arr[MAXN];

int main()
{
	int t;
	while(cin >> t)
	{
		ll cnt = 0, ans = INF;
		for(int i = 0; i < t; ++i)
		{
			cin >> arr[i];
			cnt += arr[i];
			ans = min(cnt, ans);
		}
		printf("%lld\n", ans < 0 ? -ans : 0);
	}
}