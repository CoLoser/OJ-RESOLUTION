#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 20005;
int arr[maxn];

int main()
{
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF)
	{
		int i = 0;
		for(i = 0; i < n; ++i) cin >> arr[i];
		for(; i < n + m; ++i) cin >> arr[i];
		sort(arr, arr+m+n);
		
		int len = unique(arr, arr+m+n) - arr;
		for(i = 0; i  < len; ++i) printf("%d%c", arr[i], i == len - 1 ? '\n' : ' ');
	}
}