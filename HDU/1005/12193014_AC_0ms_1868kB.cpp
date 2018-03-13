#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 55;
int arr[MAXN];


int main()
{
	int a, b, n;
	while(scanf("%d%d%d", &a, &b, &n) != EOF)
	{
		if(a == 0 && b == 0 && n == 0) break;
		arr[0] = 0;
		arr[1] = 1;
		arr[2] = 1;
		for(int i = 3; i < 49; ++i)
			arr[i] = (a*arr[i-1] + b*arr[i-2]) % 7;     //f[n]=a*f[n-1]+b*f[n-2]最多会有7*7 = 49 种可能
		
		printf("%d\n", arr[n%49]);
	}
	return 0;
}