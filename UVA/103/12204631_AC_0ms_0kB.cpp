#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 40;
struct _Node{
	int dimension;
	int id;
	int box[11];
};
_Node arr[MAXN];
int g[MAXN][MAXN];
int ans[MAXN];
int w;
int dp(int i, int n)	{
    if(ans[i] > 0)
        return ans[i];
    ans[i] = 1;
    for(int j = 0 ; j < n;j++){
        if (g[i][j]) {
            ans[i] = ans[i] > dp(j, n) + 1 ? ans[i] : dp(j, n) + 1;
        }
    }
    return ans[i];
}
void print(int i, int n) {
    if (!(w++))
        printf("%d",i + 1);
    else
        printf(" %d",i + 1);
    for(int j = 0; j < n ;j++) {
        if (g[i][j] && ans[i] == ans[j]  + 1) {
            print(j, n);
            break;
        }
    }
}
int main()
{
	int n, d, x;
	while(scanf("%d%d", &n, &d) != EOF)
	{
		memset(ans, 0, sizeof(ans));
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < d; ++j)
			{
				scanf("%d", &x);
				arr[i].box[j] = x;
			}
			arr[i].id = i + 1;
			sort(arr[i].box, arr[i].box + d);
		}
		int flag = 1;
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				flag = 1;
				g[i][j] = 1;
				for(int k = 0; k < d; ++k)
				{
					if(arr[i].box[k] >= arr[j].box[k])
					{
						flag = 0;
						break;
					}
				}
				if(!flag) g[i][j] = 0;
			}
		}
		for (int i = 0 ; i < n ;i++) {
            dp(i, n);
        }
        int m = 0;
        int res;
        for (int i = 0 ;i < n ;i++) {
            if (ans[i] > m) {
                m = ans[i];
                res = i;
            }
        }
        printf("%d\n",m);
        w = 0;
        print(res, n);
        printf("\n");
		
	}
}