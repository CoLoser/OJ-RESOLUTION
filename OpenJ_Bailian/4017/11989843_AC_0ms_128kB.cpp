#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 35;
int arr[MAXN];

int main()
{
	arr[1] = 1;
	arr[2] = 2;
	for(int i = 3; i < MAXN; ++i)
		arr[i] = arr[i - 1] + arr[i - 2];
	int t;
	while(scanf("%d", &t) != EOF)
		printf("%d\n", arr[t]);
}