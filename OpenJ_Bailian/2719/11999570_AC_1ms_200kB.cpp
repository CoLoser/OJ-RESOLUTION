#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 11;
int arr[MAXN];

int main()
{
	int n;
	
	for(int i = 0; i < 10; ++i)
		scanf("%d", &arr[i]);
		
	scanf("%d", &n);
	int cnt = 0;
	for(int i = 0; i < 10; ++i)
		if(arr[i] <= n + 30) cnt ++;
	printf("%d\n", cnt);
	return 0;
}