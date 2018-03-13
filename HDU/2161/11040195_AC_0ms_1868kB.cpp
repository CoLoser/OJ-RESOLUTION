#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

bool judge(int n){
	bool flag = true;
	for(int i = 2; i < sqrt(n + 0.5); ++i){
		if(n % i == 0) flag = false;
	}
	return flag;
}
int main(){
	int n;
	int idx = 0;
	while(scanf("%d", &n) != EOF && n > 0){
		if(n == 1 || n == 2){
			printf("%d: no\n", ++idx);
			continue;
		}
		bool flag = judge(n);
		if(flag) printf("%d: yes\n", ++idx);
		else printf("%d: no\n", ++idx);
	}
}