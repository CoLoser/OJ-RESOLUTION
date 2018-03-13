#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1005;
int arr[maxn];

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) scanf("%d", &arr[i]);
		sort(arr, arr + n);
		for(int i = 0; i < n; ++i) printf("%d%c", arr[i], i == n - 1 ? '\n' : ' ');
	}
	return 0;
}