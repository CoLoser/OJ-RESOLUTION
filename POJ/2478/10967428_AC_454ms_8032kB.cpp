#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1e6 + 5;
long long fn[maxn] = {0, 1,};
long long ans = 0;
void cla(){
	for(int i = 2; i < maxn; ++i) fn[i] = i;
	for(int i = 2; i < maxn; ++i){
		if(fn[i] == i)
		for(int j = i; j < maxn; j += i)
			fn[j] = (fn[j] / i) * (i - 1);
	}
}
int main(){
	long long n;
	cla();
	while(scanf("%lld", &n) != EOF && n){
		ans = 0;
		for(int i = 2; i <= n; ++i)
			ans += fn[i];
		printf("%lld\n", ans);
	}
	return 0;
}