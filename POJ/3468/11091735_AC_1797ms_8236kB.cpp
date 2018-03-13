#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;

const int maxn = 100010;

struct node{
	int l, r;
	ll sum;
	int mid(){
		return (l + r)>>1;
	}
};
node tree[maxn*4];
ll value[maxn];
ll visit[maxn*4];

void pushDown(int root, int len){
	
	if(visit[root]){
		visit[root<<1] += visit[root];
		visit[root<<1|1] += visit[root];
		tree[root<<1].sum += visit[root]*(len - (len>>1));
		tree[root<<1|1].sum += visit[root]*(len>>1);
		visit[root] = 0;
	}
}

void pushUp(int root){
	tree[root].sum = tree[root<<1].sum + tree[root<<1|1].sum;
}

void init(int root, int l, int r){
	tree[root].l = l;
	tree[root].r = r;
	
	if(l == r){
		tree[root].sum = value[l];
		return;
	}
	
	int m = (l + r) >> 1;
	
	init(root<<1, l, m);
	init(root<<1|1, m + 1, r);
	
	tree[root].sum = tree[root<<1].sum + tree[root<<1|1].sum;
	pushUp(root);
}

void update(int root, int op, int ed, int val){
	if(op == tree[root].l && ed == tree[root].r){
		visit[root] += val;
		tree[root].sum += (ll)((ed - op + 1) * val);
		return;
	}
	if(tree[root].l == tree[root].r){
		return;
	}
	
	int m = tree[root].mid();
	
	pushDown(root, tree[root].r - tree[root].l + 1);
	
	if(op > m) update(root<<1|1, op, ed, val);
	else if(ed <= m)update(root<<1, op, ed, val);
	else{
		update(root<<1, op, m, val);
		update(root<<1|1, m+1, ed, val);
	}
	tree[root].sum = tree[root<<1].sum + tree[root<<1|1].sum;
	
	pushUp(root);
}

ll query(int root, int l, int r){
	if(tree[root].l == l && tree[root].r == r){
		return tree[root].sum;
	}
	
	pushDown(root, tree[root].r - tree[root].l + 1);
	
	int m = tree[root].mid();
	
	if(l > m) return query(root<<1|1, l, r);
	else if(r <= m) return query(root<<1, l, r);
	else return query(root<<1, l, m) + query(root<<1|1, m + 1, r);
	
}
int main(){
	int n, q;
	char key[10];
	int a, b, c;
	while(scanf("%d%d", &n, &q) != EOF){
		memset(visit, 0, sizeof(visit));
		for(int i = 1; i <= n; ++i) scanf("%lld", &value[i]);
		init(1, 1, n);
		while(q--){
			scanf("%s", key);
            if(key[0] == 'Q'){
            	scanf("%d%d", &a, &b);
            	printf("%lld\n", query(1, a, b));
			}else if(key[0] == 'C'){
				scanf("%d%d%d", &a, &b, &c);
				update(1, a, b, c);
			}
		}
	}
	return 0;
}