#include <iostream>

using namespace std;
typedef long long ll;

int main()
{
	ll t;
	while(scanf("%lld", &t) != EOF && t)
	{
		printf("%lld\n", (t-1)/2);
	}
}