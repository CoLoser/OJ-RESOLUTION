#include <iostream>
#include <cstdio>

using namespace std;

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int a, b;
		cin >> a >> b;
		printf("%s\n", gcd(a, b) == 1 ? "NO" : "YES");
	}
	return 0;
}