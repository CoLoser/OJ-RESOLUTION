#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	int n, cur, d;
	int kase = 1;
	while(scanf("%d%d%d", &n, &cur, &d) != EOF){
		printf("Case #%d: ", kase++);
		if(cur == 1) printf("[<<]");
		else printf("(<<)");
		if(cur - d > 1){
			printf("[...]");
		} 
		for(int i = max(cur - d, 1); i < cur; ++i){
				printf("(%d)", i);
		}
		printf("[%d]", cur);
		for(int i = cur + 1; i <= min(cur + d, n); ++i){
			printf("(%d)", i);
		}
		if(n - cur > d) printf("[...]");
		if(cur == n) printf("[>>]");
		else printf("(>>)");
		printf("\n");
	}
}