#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1000005;
int arr[maxn];

int main()
{
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF)
	{
		for(int i = 0; i < n; ++i) scanf("%d", &arr[i]);
		sort(arr, arr+n);
		for(int i = n - 1; i > n  - m - 1; --i)printf("%d%c", arr[i], i == n - m?'\n':' ');
	}
	return 0;
}