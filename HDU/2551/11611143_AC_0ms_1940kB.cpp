#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;
typedef long long ll;

int main()
{
	int t;
	ll n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		ll tmp = 0;
		int i;
		for(i = 1; tmp < n; ++i)
		{
			tmp +=  i*i*i;
		}
		cout << i - 1 <<endl;
	}
}