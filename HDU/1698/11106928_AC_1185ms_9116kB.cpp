#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100005;

typedef long long ll;
struct node{
	int l, r;
	ll sum;
	int mid(){
		return (l + r)>>1;
	}
};
node tree[maxn<<2];
int value[maxn];
ll lazy[maxn<<2];

void pushUp(int root){
	tree[root].sum = tree[root<<1].sum + tree[root<<1|1].sum;
}

void pushDown(int root, int len){
	
	if(lazy[root]){
		
		lazy[root<<1] = lazy[root];
		lazy[root<<1|1] = lazy[root];
		
		tree[root<<1].sum = lazy[root] *(len - (len>>1));
		tree[root<<1|1].sum = lazy[root] * (len>>1);
		
		lazy[root] = 0;
	}
}

void init(int root, int l, int r){
    tree[root].l = l;
    tree[root].r = r;

    if(l == r){
    	tree[root].sum = 1;
		return ;
	}

	int m = (l + r)>>1;

	init(root<<1, l, m);
	init(root<<1|1, m + 1, r);

	pushUp(root);
}


void update(int root, int op, int ed, int val){ //从[op, ed]区间
    if(op == tree[root].l && ed == tree[root].r){
        lazy[root] = val;
        tree[root].sum = (ll)((ed - op + 1) * val);
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
    //tree[root].sum = tree[root<<1].sum + tree[root<<1|1].sum;

    pushUp(root);
}
int main(){
	int t, n, p;
	int a, b, v;
	scanf("%d", &t);
	int cnt = 0;
	while(t--){
		scanf("%d%d", &n, &p);
		memset(lazy, 0, sizeof(lazy));
		
		init(1, 1, n);

		while(p--){
			scanf("%d%d%d", &a, &b, &v);
			update(1,a,b,v);
		}
		printf("Case %d: The total value of the hook is %lld.\n", ++cnt, tree[1].sum);
	}
	return 0;
}