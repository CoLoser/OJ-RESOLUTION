#include <iostream>
#include <cstdio>

using namespace std;
const int INF = 0x3fffffff;
const int maxn = 105;
int arr[maxn];
int main()
{
	int n;
	while(scanf("%d", & n) != EOF && n)
	{
		int MIN = INF;
		int idx = 0;
		for(int i = 0; i < n; ++i)
		{
			scanf("%d", &arr[i]);
			if(arr[i] < MIN)
			{
				MIN = arr[i];
				idx = i;
			}
		}
		swap(arr[0], arr[idx]);
		for(int i = 0; i < n; ++i)
		{
			printf("%d%c", arr[i], i == n-1?'\n':' ');
		}
	}
	return 0;
}