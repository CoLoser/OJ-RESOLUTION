#include <iostream>
#include <cstdio>

using namespace std;

const int BASE = 10;
int reverse(int n)
{
	int ans = 0;
	while(n)
	{
		ans *= BASE;
		ans += n%BASE;
		n /= BASE;
	}
	return ans;
}
int main()
{
	int n;
	while(cin >> n)
	{
		cout << reverse(n) << endl;
	}
}