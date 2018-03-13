#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 22;

int fun(int m, int n)
{
	if(m == 0 || n == 1) return 1;
	else if(n > m) return fun(m, m);
	else
		return fun(m - n, n) + fun(m, n - 1);
}
int main()
{
	int t, a, b;
	cin >> t;
	while(t--)
	{
		cin >> a >> b;
		cout << fun(a, b) <<endl;
	}
}