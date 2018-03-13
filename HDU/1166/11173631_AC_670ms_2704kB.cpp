#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn = 50005;
ll tree[maxn<<1];
int n;

inline int lowbit(int x){
	return -x&x;
}

void update(int idx, int val){
	while(idx <= n){
		tree[idx] += val;
		idx += lowbit(idx);
	}
}

ll query(int idx){
	ll ans = 0;
	while(idx > 0){
		ans += tree[idx];
		idx -= lowbit(idx);
	}
	return ans;
}
int main(){
	int t;
	scanf("%d", &t);
	int cnt = 1;
	while(t--){
		memset(tree, 0, sizeof(tree));
		printf("Case %d:\n", cnt++);
		scanf("%d", &n);
		int m;
		for(int i = 1; i <= n; ++i){
			scanf("%d", &m);
			update(i, m);
		}
		char key[10];
		int a, b;
		while(scanf("%s", key) != EOF && key[0] != 'E'){
			scanf("%d%d", &a, &b);
			if(key[0] == 'A') update(a, b);
			else if(key[0] == 'S') update(a, -b);
			else cout << query(b) - query(a-1) <<endl;
		}
	}
	return 0;
}