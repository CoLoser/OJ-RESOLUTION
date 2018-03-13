#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <set>  
using namespace std;  
#define MAX 65  
typedef unsigned long long ll;  
  
bool prime[MAX];  
set<ll> myset;  
  
ll power(int a, int n) {  
    if(n == 0) return 1LL;  
    ll ans = power(a, n/2);  
    ans *= ans;  
    if(n%2 == 1) ans *= a;  
    return ans;  
}  
  
void init() {  
    memset(prime, false, sizeof(prime));  
    for(int i = 2; i < MAX; ++i)   
        if(!prime[i]) {  
        for(int j = 2*i; j < MAX; j += i)  
            prime[j] = true;  
    }  
}  
  
int main(){  
    init();  
    myset.clear();  
    myset.insert(1);  
     
    double lnmax = log( pow(2.0, 64.0)-1 );  
    for(int i = 2; i < (1<<16); ++i) {  
        int maxe = (int)ceil(lnmax/log(i));  
        for(int j = 4; j < maxe; ++j)   
            if( prime[j] ) {  
            ll temp = power(i, j);  
            if(!myset.count(temp))  
                myset.insert(temp);  
        }  
    }  
     
    for(set<ll>::iterator it = myset.begin(); it != myset.end(); ++it)  
        printf("%llu\n", *it);   
    return 0;  
}  