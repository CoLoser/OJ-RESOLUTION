#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 105;
int arr[maxn];

bool cmp(int a, int b)
{
	return abs(a) > abs(b);
}
int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		for(int i = 0; i < n; ++i)scanf("%d", &arr[i]);
		sort(arr, arr + n, cmp);
		for(int i = 0; i < n; ++i) printf("%d%c", arr[i], i == n - 1? '\n' : ' ');
	}
	return 0;
}