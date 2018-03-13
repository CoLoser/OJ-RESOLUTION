#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 15;
int arr[MAXN];

int main()
{
	int t, n;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%d", &arr[i]);
		sort(arr, arr + n);
		printf("%d\n", arr[1]);
	}
	return 0;
}