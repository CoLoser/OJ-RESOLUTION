#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 105;
int arr[maxn][maxn];

int main()
{
	int t, n;
	cin>>t;
	while(t--)
	{
		scanf("%d", &n);
		memset(arr, 0, sizeof(arr));
		for(int i = 0; i < n; ++i)
			for(int j = 0; j <= i; ++j)
				scanf("%d", &arr[i][j]);
		for(int i = n-2; i >= 0; --i)
			for(int j = 0; j <= i; ++j)
				arr[i][j] += max(arr[i+1][j], arr[i+1][j+1]);
		printf("%d\n", arr[0][0]);
	}
}