#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e6 + 1;

int arr[MAXN];

int main()
{
	arr[0] = 7 % 3;
	arr[1] = 11 % 3;
	for(int i = 2; i < MAXN; ++i) arr[i] = (arr[i-1] + arr[i-2]) % 3;
	int n;
	while(scanf("%d", &n) != EOF)
	{
		printf("%s\n", arr[n]%3 ? "no" : "yes");
	}
	return 0;
}