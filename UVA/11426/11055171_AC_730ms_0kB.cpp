#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
typedef long long ll;

const int maxn = 4e6 + 5;
int phi[maxn];
ll s[maxn], f[maxn];
void phi_table(int n){
    for(int i = 2; i <= n; ++i)phi[i] = 0;
	phi[1] = 1;
	for(int i = 2; i <= n; ++i)if(!phi[i])
		for(int j = i; j <= n; j+=i){
			if(!phi[j]) phi[j] = j;
			phi[j] = phi[j]/i*(i-1);
		}
}
void init(){
	memset(f, 0, sizeof(f));
	for(int i = 1; i <= maxn; ++i)
		for(int n = i*2; n <= maxn; n += i) f[n] += i * phi[n/i];

	s[2] = f[2];
	for(int n = 3; n <= maxn; n++) s[n] = s[n-1] + f[n];
	
}
int main(){
	phi_table(maxn);
	init();

	int n;
	while(scanf("%d", &n) != EOF && n){
		printf("%lld\n", s[n]);
	}

}