#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long ll;
using namespace std;
const ll maxn = 1e8+10100;
int prime[maxn];

void init(){
	memset(prime, 0, sizeof(prime));
	prime[1] = 1;
	for(int i = 2; i < maxn; ++i) if(!prime[i])
		for(int j = 2*i; j <= maxn; j+=i) prime[j] = 1;
}
int getNum(int a, int b){
	int ans = 0;
	for(int i = a; i <=b; ++i){
		ll t = i*i + i + 41;
		if(!prime[t]) ans++;
	}
	return ans;
}
int main(){
	int a, b, ans;
	init();
	while(~scanf("%d %d", &a, &b)){
		ans = getNum(a, b);
		printf("%.2f\n", ans*1.0/(b-a+1) * 100 +1e-8);
	}
	return 0;
}