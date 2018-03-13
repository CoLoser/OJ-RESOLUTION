#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 200005;
int arr[MAXN];
int sum[MAXN];
int main()
{
	int n, m, k;
	int t;
	cin >> t;
	while(t--)
	{
		scanf("%d%d%d", &n, &m, &k);
		int x;
		sum[0] = 0;
		ll ans = 0;
		for(int i = 1; i <= n; ++i)
		{
			scanf("%d", &x);
			if(x<m)
				arr[i] = 0;
			else
				arr[i] = 1;
			sum[i] = sum[i-1] + arr[i];
		}
		
		int l, r = 1;
		for(l = 1; l <= n; ++l)
		{
			while(r<=n && sum[r] - sum[l-1] < k)
				r++;

			if(r > n) break;
			ans += (n - r + 1);
		}
		cout << ans <<endl;
	}
}