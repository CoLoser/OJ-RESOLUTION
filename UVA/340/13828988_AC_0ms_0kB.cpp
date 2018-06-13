#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 1005;
int a[MAXN], b[MAXN];
int t1[10], t2[10];
int main() {
	int n;
	int kase = 0;
	while(cin >> n && n) {
		printf("Game %d:\n", ++kase);
		int x = 0, y = 0;
		for(int i = 0; i < n; ++i) cin >> a[i];
		bool flag = true;
		while(1) {
			flag = true;
			x = y = 0;
			memset(t1, 0, sizeof(t1));
			memset(t2, 0, sizeof(t2));
			for(int i = 0; i < n; ++i) {
				cin >> b[i];
				t1[a[i]]++;
				t2[b[i]]++;
				if(a[i] == b[i]) x++;
				if(b[i] != 0) flag = false;
			}
			if(flag) break;
			for(int i = 0 ; i < 10; ++i) {
				y += min(t1[i], t2[i]);
			}
			printf("    (%d,%d)\n", x, y - x);
		}
	}
	return 0;
}