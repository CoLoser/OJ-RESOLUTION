#include <iostream>
#include <cstdio>

using namespace std;

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);
}

int main()
{
	int a, b;
	while(cin >> a >>b)
	{
		int ans = gcd(a, b);
		printf("%d 0x%x 0%o\n", ans, ans, ans);
	}
	return 0;
}