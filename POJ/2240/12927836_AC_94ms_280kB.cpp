#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 40;
double E[MAXN][MAXN];
map<string, int> money;
int n, m;

void floyd() {
	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				E[i][j] = max(E[i][j], E[i][k]*E[k][j]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s, s1 ,s2;
	double rate;
	int cnt = 0;
	while(cin >> n && n) {
		for(int i = 1; i <= n; ++i) {
			cin >> s;
			money[s] = i;
		}
		cin >> m;
		for(int i = 0; i <= n; ++i)
			for(int j = 0; j <= n; ++j)
				E[i][j] = (i == j ? 1 : 0);
		for(int i = 1; i <= m; ++i) {
			cin >> s1 >> rate >> s2;
			E[money[s1]][money[s2]] = rate;
		}
		floyd();
		printf("Case %d: ", ++cnt);
		for(int i = 1; i <= n; ++i)
			if(E[i][i] > 1) {
				printf("Yes\n");
				break;
			}else if(n == i) printf("No\n");
	}
	return 0;
}