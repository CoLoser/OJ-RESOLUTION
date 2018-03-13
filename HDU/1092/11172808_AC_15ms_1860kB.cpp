#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int n;
	int sum = 0;
	while(scanf("%d", &n) != EOF && n){
		sum = 0;
		int x;
		for(int i = 0; i < n; ++i)
		{
			scanf("%d", &x);
			sum += x;
		}
		printf("%d\n", sum);
	}
	return 0;
}