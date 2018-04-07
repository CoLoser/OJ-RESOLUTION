#include <iostream>
#include <cstdio>

using namespace std;
int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		int sum = 0;
		for(int i = 0; i <= n; ++i) if(i % 3 == 0) sum += i;
		printf("%d\n", sum);
	}
	return 0;
}