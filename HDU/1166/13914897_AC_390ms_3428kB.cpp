#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 50005;
struct Tree{
	int left, right, value;
	int mid(){
		return (left + right)>>1;
	}
};
Tree tree[MAXN*4];
int value[MAXN];
char order[MAXN];

void push_up(int root){
    tree[root].value = tree[root<<1].value + tree[root<<1|1].value;
}
void init(int root, int l, int r){
    tree[root].left=l; tree[root].right=r;
    if(l==r){
        tree[root].value = value[l];
        return;
    }
    init(root<<1, l, (l+r)/2);
    init(root<<1|1, (l+r)/2 + 1, r);
    push_up(root);
}
void update(int root, int idx, int value){
    if(tree[root].left == tree[root].right){
        tree[root].value = value;
        return;
    }
    if(idx <= tree[root].mid()) update(root<<1, idx, value);
    else update(root<<1|1, idx, value);

    push_up(root);
}
int query(int root, int l, int r){
    if(l <= tree[root].left && r >= tree[root].right)
        return tree[root].value;
    int mid = tree[root].mid(), res = 0;

    if(l <= mid) res += query(root<<1, l, r);
    if(r > mid) res += query(root<<1|1, l, r);

    return res;
}
int main()
{
    int t, n, m;
    scanf("%d", &t);
    for(int i = 1; i <= t; ++i){
        scanf("%d", &n);
        for(int j = 1; j <= n; ++j) scanf("%d",&value[j]);
        init(1, 1, n);
        int l, r;
				int cnt = 0;
        printf("Case %d:\n", i);
        while(scanf("%s", order) != EOF && order[0] != 'E' && cnt++ <= 40000){
            scanf("%d%d", &l, &r);
            if(order[0] == 'Q'){
               if(l > r) swap(l, r);
                printf("%d\n", query(1,l, r));
            }else if(order[0] == 'A'){
                value[l] += r;
                update(1, l, value[l]);
            }
            else{
                value[l] -= r;
                update(1, l, value[l]);
            }
        }
    }
    return 0;
}
