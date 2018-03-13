#include <iostream>
#include <cstdio>

using namespace std;

int cal(int val, int base)
{
	int ans = 0;
	while(val > 0)
	{
		ans += val%base;
		val /= base;
	}
	return ans;
}
int main()
{
	int n;
	while(scanf("%d", &n) != EOF && n)
	{
		int t1 = cal(n, 10);
		int t2 = cal(n, 12);
		int t3 = cal(n, 16);
		
		if(t1 == t2 && t1 == t3)
			printf("%d is a Sky Number.\n", n);
		else
			printf("%d is not a Sky Number.\n", n);
	}
	return 0;
}