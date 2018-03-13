#include <cstdio>

using namespace std;
typedef long long ll;
ll gcd(ll a, ll b){
	return b == 0 ? a : gcd(b, a%b);
}

int main()
{
	ll a, b;
	while(scanf("%d%d", &a, &b) != EOF){
		printf("%lld\n", a*b/gcd(a, b));
	}
	return 0;
}