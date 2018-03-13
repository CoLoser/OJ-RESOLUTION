#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 20005;
int dragons[maxn];
int knights[maxn];

int main()
{
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF)
	{
		if(n == 0 && m == 0) break;
		for(int i = 0; i < n; ++i)
			scanf("%d", &dragons[i]);
		for(int j = 0; j < m; ++j)
			scanf("%d", &knights[j]);

		sort(dragons, dragons + n);
		sort(knights, knights + m);
		
		int ans = 0;
		int cur = 0;
		for(int i = 0; i < m; ++i)
		{
			if(dragons[cur] <= knights[i]){
				ans += knights[i];
				if(++cur == n) break;
			}
		}
		if(cur < n) printf("Loowater is doomed!\n");
		else printf("%d\n", ans);
	}
	return 0;
}