#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 15;
char grid[MAXN][MAXN];
int main() {
	int t, n;
	cin >> t;
	for(int kase = 1; kase <= t; ++kase) {
		cin >> n;
		for(int i = 0; i < n; ++i) cin >> grid[i];

		for(int i = 0; i < n; ++i) {

			for(int j = 0; j < n; ++j) {

				if(grid[i][j] == '.') {
					for(char ch = 'A'; ch <= 'Z'; ++ch) {
						bool ok = true;
						if(i > 0 && grid[i - 1][j] == ch) ok = false;
						if(i < n - 1 && grid[i + 1][j] == ch) ok = false;
						if(j > 0 && grid[i][j - 1] == ch) ok = false;
						if(j < n - 1 && grid[i][j + 1] == ch) ok = false;

						if(ok) {
							grid[i][j] = ch;
							break;
						}
					}
				}
			}
		}
		printf("Case %d:\n", kase);
		for(int i = 0; i < n; ++i) cout << grid[i] << endl;
	}
	return 0;
}