#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;
int extgcd(ll a, ll b, ll &x, ll &y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}else{
		ll ans = extgcd(b, a%b, x, y);
        ll t = x;
        x = y;
        y = t - a/b*y;
        return ans;
	}
}
int cal(ll a, ll b, ll d){
    ll x, y;
    ll gcd = extgcd(a, b, x, y);
    if(d % gcd != 0) return -1;
    x = x*d/gcd;
    b = b/gcd;
    if(b < 0) b = -b;
    ll ans = x%b;
    if(ans < 0) ans += b;
    return ans;
}
int main(){
	ll x, y, m, n, l;
	while(scanf("%lld%lld%lld%lld%lld", &x, &y, &m, &n, &l) != EOF){
        ll ans = cal(m-n, l, y-x);
        if(ans == -1) printf("Impossible\n");
        else printf("%lld", ans);
	}
}
