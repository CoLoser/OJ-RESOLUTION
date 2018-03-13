#include <iostream>
#include <cstdio>

using namespace std;


typedef long long ll;
const ll MOD = 9973;
int main()
{
	int t;
	ll a, b;
	cin >> t;
	while(t--)
	{
		cin >> a >> b;
		for(int i = 0; i < MOD; ++i)
			if((i * b - a) % MOD == 0)
			{
				cout << i <<endl;
				break;
			}
	}
	return 0;
}