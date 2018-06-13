#include <iostream>
#include <algorithm>
using namespace std;

//一个长方体有六种摆放方式
const int MAXN = 200;
int dp[MAXN];	//dp[i] 表示前i个方块堆起来的最大值 

struct _Node{
	int x, y, z;
	bool operator < (const _Node rhs) const{
		if(rhs.x == x) return y > rhs.y;
		else return x > rhs.x;
	}
};
_Node a[MAXN];
int x, y, z;
int main(){
	int n;
	int kase = 0;
	while(cin >> n && n)	{
		int cnt = 0;
		for(int i = 0; i < n; ++i){
			cin >> x >> y >> z;
			a[cnt].x = x, a[cnt].y = y, a[cnt++].z = z;
			a[cnt].x = x, a[cnt].y = z, a[cnt++].z = y;
			a[cnt].x = y, a[cnt].y = x, a[cnt++].z = z;
			a[cnt].x = y, a[cnt].y = z, a[cnt++].z = x;
			a[cnt].x = z, a[cnt].y = y, a[cnt++].z = x;
			a[cnt].x = z, a[cnt].y = x, a[cnt++].z = y;
		}
		sort(a, a+cnt);
		dp[0] = a[0].z;
		for(int i = 0; i < cnt; ++i){
			int tmp = 0;
			for(int j = 0; j <= i; ++j){
				if(a[j].x > a[i].x && a[j].y > a[i].y) tmp = max(tmp, dp[j]);
			}
			dp[i] = a[i].z + tmp; 
		}
		int ans = 0;
		
		for(int i = 0 ; i < cnt; ++i)
			ans = max(dp[i], ans);
		printf("Case %d: maximum height = %d\n",++kase, ans);
	}
	return 0;
}