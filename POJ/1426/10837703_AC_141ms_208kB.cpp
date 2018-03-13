#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

typedef unsigned __int64 ull;

bool visit;

void dfs(ull m, int n, int k){
	if(visit) return;
	if(m % n == 0){
		printf("%I64u\n", m);
		visit = true;
		return;
	}
	if(k == 19) return;
	dfs(10 * m, n, k + 1);
	dfs(10 * m + 1, n, k + 1);
}
int main(){
	int n;
	while(scanf("%d", &n) != EOF && n){
		visit = false;
		dfs(1, n, 0);
	}
	return 0;
}