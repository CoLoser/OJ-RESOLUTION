#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1005;
struct _Node {
	int w, s, no;
	bool operator < (const _Node rhs){
		if(w == rhs.w) return s > rhs.s;
		else return w > rhs.w;
	}
};
_Node mos[MAXN];
int dp[MAXN];
int path[MAXN];

int main(){
	int a, b;
	int cnt = 0;
	while(cin >> a >> b){
		mos[cnt].no = cnt;
		mos[cnt].w = a;
		mos[cnt++].s = b;
	}
	sort(mos, mos+cnt);
	//for(int i = 0; i < cnt; ++i) cout << mos[i].no << " " << mos[i].w << " " << mos[i].s << endl;
	
	int k = -1;
	int res = 0;
	for(int i = 0; i < cnt; ++i){
		dp[i] = 1;
		path[i] = -1;
		for(int j = 0; j < i; ++j){
			if(mos[i].w < mos[j].w && mos[i].s > mos[j].s && dp[j] + 1 > dp[i]){
				dp[i] = dp[j]+1;
				path[i] = j;
			}
		}
		
		if(res < dp[i]){
			k = i;
			res = dp[i];
		}
	}
	
	printf("%d\n", res);
	while(k != -1){
		printf("%d\n", mos[k].no+1);
		k = path[k];
	}
	return 0;
}