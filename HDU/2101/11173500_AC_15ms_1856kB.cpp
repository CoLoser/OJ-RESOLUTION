#include <cstdio>

using namespace std;
typedef long long ll;
int main()
{
	ll a, b;
	while(scanf("%lld%lld", &a, &b) != EOF){
		if((a + b) % 86 == 0) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}