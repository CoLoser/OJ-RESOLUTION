#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 200005;
typedef long long ll;

int arr[MAXN];
ll d[MAXN];    //记录大于m的数的位置
//乘法原理
int main()
{
    int t;
    int n, m, k;
    scanf("%d", &t);
    while(t--)
    {
		scanf("%d%d%d", &n, &m, &k);
		int idx = 0;
		ll ans = 0;
		for(int i = 1; i <= n; ++i)
		{
			scanf("%d", &arr[i]);
			
			if(arr[i] >= m)
			{
				d[++idx] = i;
				if(idx >= k)
				{
					if(idx == k) ans += d[1] * (n - i + 1);
					else ans += (d[idx - k + 1] - d[idx - k]) * (n - i + 1);
				}
			}
		}
		cout << ans <<endl;
	}
}