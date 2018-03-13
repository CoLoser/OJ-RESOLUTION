#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 1005;
int arr[MAXN];

int main()
{
	int t, n;
	scanf("%d", &t);
	while(t--)
	{
		memset(arr, 0, sizeof(arr));
		scanf("%d", &n);
		int x;
		for(int i = 0; i < n; ++i)
		{
			scanf("%d", &x);
			arr[x]++;
		}
		int MAX1 = -1, MAX2 = -1;
		int idx1 = 0, idx2 = 0;
		for(int i = 0; i < MAXN; ++i)
		{
			if(MAX1 <= arr[i])
			{
				idx1 = i;
				MAX1 = arr[i];
			}
		}
		for(int i = MAXN - 1; i >= 0; --i)
		{
			if(MAX2 <= arr[i])
			{
				idx2 = i;
				MAX2 = arr[i];
			}
		}
		if(idx1 != idx2) printf("Nobody\n");
		else printf("%d\n", idx1);
	}
}