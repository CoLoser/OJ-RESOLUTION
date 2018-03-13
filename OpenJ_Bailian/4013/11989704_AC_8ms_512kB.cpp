#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 15005;
int arr[MAXN];

int main()
{
	int n;
	while(scanf("%d", &n) != EOF && n)
	{
		for(int i = 0; i < n; ++i)
			scanf("%d", &arr[i]);

		sort(arr, arr+n);
		printf("%d\n", (n%2) ? arr[n/2] : (arr[n/2] + arr[n/2 - 1])/2);
	}
}