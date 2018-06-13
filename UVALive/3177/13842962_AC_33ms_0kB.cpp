#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 100005;
int r[MAXN], Left[MAXN], Right[MAXN];
int n;


bool test(int p) {
	int x = r[1], y = p - r[1];
	Left[1] = x, Right[1] = 0;

	for(int i = 2; i <= n; ++i) {
		if(i % 2 == 1) {
			Right[i] = min(r[i], y-Right[i - 1]);
			Left[i] = r[i] - Right[i];
		} else {
			Left[i] = min(r[i], x - Left[i - 1]);
			Right[i] = r[i] - Left[i];
		}
	}
	return Left[n] == 0;
}
int main() {
	while(scanf("%d", &n) != EOF && n) {
		for(int i = 1; i<= n; ++i) scanf("%d", &r[i]);
		if(n == 1) {
			printf("%d\n", r[1]);
			continue;
		}
		r[n + 1] = r[1];

		int L = 0, R = 0;

		for(int i = 1; i <= n; ++i) L = max(L, r[i] + r[i + 1]);		//找出最大的， 当为偶数时为最大

		if(n % 2 == 1) {
			for(int i = 1; i <= n; ++i) R = max(R, r[i]*3); 		//r[i]*3 肯定可以满足情况

			while(L < R) {
				int M = L + (R - L)/2;
				if(test(M)) R = M;
				else L = M + 1;
			}
		}
		printf("%d\n", L);
	}
	return 0;
}