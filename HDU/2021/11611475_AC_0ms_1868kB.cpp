#include <iostream>
#include <cstdio>

using namespace std;

int coin[6] = {100, 50, 10, 5, 2, 1};
int cal(int n)
{
	int ans = 0;
	for(int i = 0; i < 6; ++i)
	{
		ans += n/coin[i];
		n %= coin[i];
	}
	return ans;
}
int main()
{
	int t;
	while(scanf("%d", &t) != EOF && t)
	{
		int ans = 0;
		int tmp;
		while(t--)
		{
			scanf("%d", &tmp);
			ans += cal(tmp);
		}
		printf("%d\n", ans);
	}
}