#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;

ll extgcd(ll a, ll b, ll &x, ll &y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	ll ans = extgcd(b, a%b, x, y);
    ll t = x;
    x = y;
    y = t - a/b*y;
    return ans;
}
//计算乘法逆元
ll cal(ll a, ll b, ll d){
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
    ll a, b, c;
    int k;
    while(scanf("%lld%lld%lld%d", &a, &b, &c, &k) != EOF){
        if(a == 0 && b == 0 && c == 0 && k == 0) break;
        ll l = ((ll)1<<k);
        ll ans = cal(c, l, b-a);
        if(ans == -1) printf("FOREVER\n");
        else printf("%lld\n", ans);
    }
    return 0;
}