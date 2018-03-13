#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;
stack<char> sta;
int n, r;

void cla(){
	if(n < 0){
		n = -n;
	}
	while(n != 0){
		int temp = n % r;
		if(temp >= 10) sta.push(('A' + temp - 10));
		else sta.push(temp + '0');
		n /= r;
	}
}
int main(){
	while(scanf("%d%d", &n, &r) != EOF){
		while(!sta.empty()) sta.pop();
		if(n < 0) printf("-");
		cla();
		while(!sta.empty()){
			printf("%c", sta.top());
			sta.pop();
		}
		printf("\n");
	}
	return 0;
}