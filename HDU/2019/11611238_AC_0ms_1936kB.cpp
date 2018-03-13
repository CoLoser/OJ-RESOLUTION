#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXN = 200;
int arr[MAXN];

int main()
{
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF)
	{
		if(n == 0 && m == 0) break;
		for(int i = 0; i < n; ++i) cin >> arr[i];
		arr[n] = m;
		sort(arr, arr + 1 + n);
		for(int i = 0; i <= n; ++i)
			printf("%d%c", arr[i], i == n ? '\n' : ' ');
	}
	return 0;
}