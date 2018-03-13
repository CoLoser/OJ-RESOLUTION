#include <iostream>
#include <cstdio>

using namespace std;

const int MOD = 1000;
int main()
{
	int a, b, ans;
	while(scanf("%d%d", &a, &b) != EOF)
	{
		if(a == 0 && b == 0) break;
		ans = 1;
		for(int i = 0; i < b; ++i) ans = (ans*a)%MOD;
		printf("%d\n", ans);
	}
	return 0;
}