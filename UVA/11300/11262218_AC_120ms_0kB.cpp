#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

const int maxn = 1000005;
ll x[maxn], a[maxn], tot, m;
int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		tot = 0;
		for(int i = 1; i <= n; ++i){
			scanf("%lld", &a[i]);
			tot+=a[i];
		} 
		m = tot/n;
		x[0] = 0;
		for(int i = 1; i <= n; ++i) x[i] = m - a[i] + x[i-1];
		sort(x, x+n);
		
		ll  x1 = x[n/2], ans = 0;
		for(int i = 0; i < n; ++i) ans += fabs(x1 - x[i]);
		printf("%lld\n", ans);
	}
	return 0;
}