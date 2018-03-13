#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <iostream>
using namespace std;
#define MAX 65
typedef unsigned long long ll;

bool prime[MAX];
set<ll> se;

ll power(int a, int n) {
    if(n == 0) return 1LL;
    ll ans = power(a, n/2);
    ans *= ans;
    if(n%2 == 1) ans *= a;
    return ans;
}

int main(){
    se.clear();
    se.insert(1);
    memset(prime, false, sizeof(prime));
    for(int i = 2; i < MAX; ++i) if(!prime[i])
        for(int j = 2*i; j < MAX; j += i) prime[j] = true;
    for(int i = 2; i < (1<<16); ++i) {
        int maxe = (int)ceil((log( pow(2.0, 64.0)-1 ))/log(i));
        for(int j = 4; j < maxe; ++j)
            if( prime[j] ) {
            ll t = power(i, j);
            if(!se.count(t))
                se.insert(t);
        }
    }
    for(set<ll>::iterator it = se.begin(); it != se.end(); ++it)
        printf("%llu\n", *it);
    return 0;
}