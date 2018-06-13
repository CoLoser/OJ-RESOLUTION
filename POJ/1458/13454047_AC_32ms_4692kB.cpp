#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

/*
	Name: POJ-148
	Copyright:
	Author: YancyKahn
	Date: 12/04/18 22:22
	Description: dp LIS
*/

/*
 if a[i] == b[j] :
 		dp[i][j] = dp[i-1][j-1] + 1
else:
		dp[i][j] = max(dp[i-1][j], dp[i][j-1] )
*/
const int MAXN = 1005;
int dp[MAXN][MAXN];	//a的前i个字符和b的前j个字符的最长公共子序列长度

int main() {
	char a[1005], b[1005];
	while(cin >> a >> b) {
		int len1 = strlen(a);
		int len2 = strlen(b);
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= len1; ++i) {
			for(int j = 1; j <= len2; ++j) {
				if(a[i-1] == b[j-1])
					dp[i][j] = dp[i-1][j-1] + 1;
				else
					dp[i][j] = max(dp[i-1][j], dp[i][j-1] );
			}
		}
		cout << dp[len1][len2]<<endl;
	}
	return 0;
}