#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1000;
int arr[maxn];

int main()
{
	memset(arr, -1, sizeof(arr));
	for(int i = 100; i < maxn; ++i)
	{
		int a = i%10;
		int b = i/10%10;
		int c = i/100;
		if(i == a*a*a + b*b*b + c*c*c) arr[i] = i;
	}
	int m, n;
	while(scanf("%d%d", &m, &n) != EOF)
	{
		int flag = 0;
		for(int i = m; i <= n; ++i)
		{
			if(arr[i] != -1){
				if(!flag)
					printf("%d", arr[i]);
				else
					printf(" %d", arr[i]);
				flag = 1;
			} 
		}
		if(!flag) printf("no\n");
		else printf("\n");
	}
	return 0;
}