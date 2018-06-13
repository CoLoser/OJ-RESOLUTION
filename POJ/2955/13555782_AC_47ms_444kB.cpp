#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 150;
int dp[MAXN][MAXN];
char s[MAXN];
int main ()
{
    while(~scanf("%s", s + 1))
    {
        memset(dp, 0, sizeof(dp));
        if(s[1] == 'e') break;
        int len = strlen(s + 1);
        for(int l = 1; l <= len; l++)
            for(int i = 1; i <= len - l + 1; i++)
            {
                int j = i + l - 1;
                if((s[i] == '(' && s[j] == ')') || (s[i] == '[' && s[j] == ']'))
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                for(int k = i; k < j; k++)
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
        printf("%d\n", dp[1][len]);
    }
    return 0;
}