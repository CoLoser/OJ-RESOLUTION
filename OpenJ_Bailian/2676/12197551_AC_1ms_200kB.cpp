#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int arr[11];
int main()
{
	int k, t;
	cin >> k;
	memset(arr, 0, sizeof(arr));
	while(k--)
	{
		cin >> t;
		arr[t] ++;
	}
	printf("%d\n%d\n%d\n", arr[1], arr[5], arr[10]);
	return 0;
}