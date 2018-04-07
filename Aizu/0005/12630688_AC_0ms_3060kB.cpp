#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 2e9 + 1;
typedef unsigned long long ull;

ull gcd(ull a, ull b)
{
	return b == 0? a : gcd(b, a % b);
}

ull lcm(ull a, ull b)
{
	return a * b / gcd(a, b);
}

int main()
{
	ull a, b;
	while(cin >> a >> b)
		cout << gcd(a, b) << " " << lcm(a, b) <<endl;
	return 0;
}