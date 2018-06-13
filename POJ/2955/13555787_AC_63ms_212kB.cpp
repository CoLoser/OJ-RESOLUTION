#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 105;
int dp[MAXN][MAXN]; 	//dp[i][j]表示从i到j最长的合法括号序列
char key[MAXN];
int main() {
	while(cin >> (key+1)) {
		if(key[1] == 'e') break;
		memset(dp, 0, sizeof(dp));
		int len = strlen(key + 1);
		//cout << len << endl;
		for(int l = 1; l <= len; ++l) {
			for(int i = 1; i + l -1 <= len; ++i) {
				int j = i + l - 1;
				if((key[i] == '(' && key[j] == ')') || (key[i] =='[' && key[j] == ']')) dp[i][j] = dp[i+1][j-1] + 2;
				for(int k = i; k < j; ++k) {
					dp[i][j] = max(dp[i][k]+dp[k+1][j], dp[i][j]);
				}
			}
		}
		printf("%d\n", dp[1][len]);
	}
	return 0;
}