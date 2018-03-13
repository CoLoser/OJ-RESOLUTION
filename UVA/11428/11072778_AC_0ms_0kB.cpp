#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int maxn = 10005;
typedef long long ll;

int search(int n, int y){
	ll l = y + 1, r = y + maxn, x, k;
	while(l <= r){
		x = (l + r)/2;
		k = (x - y)*(x*x + y*y +x*y);
		if(k == n) return x;
		else if(k < n) l = x + 1;
		else if(k > n) r = x - 1;
	}
	return -1;
}
int main(){
	int n, x;
	while(cin >> n && n){
		x = -1;
		for(int y = 0; y <=60; ++y){
			x = search(n , y);
			if(x != -1){
				 printf("%d %d\n", x, y);
				 break;
			}
		}
		if(x == -1) printf("No solution\n");
	}
	return 0;
}