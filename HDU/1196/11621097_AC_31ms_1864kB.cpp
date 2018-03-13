#include <cstdio>
#include <iostream>

using namespace std;

int lowbit(int x)
{
	return x&-x;
}
int main()
{
	int n;
	while(scanf("%d", &n) != EOF && n)
		printf("%d\n", lowbit(n));
}