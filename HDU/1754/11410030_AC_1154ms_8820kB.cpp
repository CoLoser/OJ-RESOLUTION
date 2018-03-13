#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn = 200005;
int n, m;

struct node{
	int l, r;
	int MAX_VALUE;
	int mid(){
		return (l + r) >> 1;
	}
};
node tree[maxn * 4];
int value[maxn];

void init(int root, int l, int r){
	tree[root].l = l;
	tree[root].r = r;
	
	if(l == r){
		 tree[root].MAX_VALUE = value[l];
		 return;
	}
	
	int m = (l + r) >> 1;
	
	init(root<<1, l, m);
	init(root<<1|1, m+1, r);
	
	tree[root].MAX_VALUE = max(tree[root<<1].MAX_VALUE, tree[root<<1|1].MAX_VALUE);
}

void update(int root, int idx, int v){
	if(tree[root].l == tree[root].r){
		tree[root].MAX_VALUE = v;
		return;
	}
	
	if(idx <= tree[root].mid()) update(root<<1, idx, v);
	else update(root<<1|1, idx, v);
	
	tree[root].MAX_VALUE = max(tree[root<<1].MAX_VALUE, tree[root<<1|1].MAX_VALUE);
}

int query(int root, int l, int r){

	if(l == tree[root].l && r == tree[root].r) return tree[root].MAX_VALUE;
	
	int m = tree[root].mid();
	
	if(l > m) return query(root<<1|1, l, r);
	else if(r <= m) return query(root<<1, l, r);
	else return max(query(root<<1, l, m), query(root<<1|1, m+1, r));
}
int main(){
	char key[10];
	
	while(scanf("%d%d", &n, &m) != EOF){
		for(int i = 1; i <= n; ++i) scanf("%d", &value[i]);
		init(1, 1, n);
		while(m--){
			int a, b;
			scanf("%s", key);
			scanf("%d%d", &a, &b);
			if(key[0] == 'Q') printf("%d\n", query(1, a, b));
			else update(1, a, b);
		}
	}
	return 0;
}