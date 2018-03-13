#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <set>
//超级幂
using namespace std;
typedef unsigned long long ll;
const int maxn = 65;
int visit[maxn];
set<ll> s;
ll power(int a, int n) {
	ll ans = a;
    for(int i = 0; i < n - 1; ++i) ans *= a;
    return ans;
}
int main(){
	s.clear();
	s.insert(1);
	memset(visit, 0, sizeof(visit));
	for(int i = 2; i < maxn; ++i)if(!visit[i])
        for(int j = 2*i; j < maxn; j += i)visit[j] = 1;
	for(int i = 2; i < (1<<16); ++i){
		int maxe = ceil(64 * log(2) / log(i));
		for(int j = 4; j < maxe; ++j){
			if(visit[j]){
				ll t = power(i, j);
				s.insert(t);
			}
		}
	}
 	for(set<ll>::iterator it = s.begin(); it != s.end(); ++it){
		printf("%llu\n", *it);
	}
	return 0;
}