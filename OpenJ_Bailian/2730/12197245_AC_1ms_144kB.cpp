#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;
const int MAXN = 21;
ll arr[MAXN];
int main()
{
	arr[1] = 1;
	for(int i = 2; i <= 20; ++i)
	{
		arr[i] = arr[i - 1] * i;
	}
	int n;
	while(scanf("%d", &n) != EOF)
		printf("%lld\n", arr[n]);
	return 0;
}