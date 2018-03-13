#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define N 10000000
using namespace std;

typedef long long ll;
struct node{
    int l,r,mid;
    bool flag;
    ll sum;
}tree[N<<2];
ll value[N];

void build(int l,int r, int root){
    tree[root].l=l;  tree[root].r=r;  tree[root].mid=(l+r)>>1;
    tree[root].flag=1;

    if(l==r)
    {
        tree[root].sum=value[l];
        if(value[l]<=1) tree[root].flag=0;
        return ;
    }

    build(l,tree[root].mid,root<<1);
    build(tree[root].mid+1,r,root<<1|1);
    tree[root].sum=tree[root<<1].sum+tree[root<<1|1].sum;
    tree[root].flag=tree[root<<1].flag || tree[root<<1|1].flag;
}
void update(int l,int r,int root)
{
    if(tree[root].flag==0)return;
    if(tree[root].l==tree[root].r && tree[root].l==l &&tree[root].r==r)
    {
        tree[root].sum=(ll)sqrt(1.0*tree[root].sum);
        if(tree[root].sum<=1) tree[root].flag=0; //标记为0  就不找了
        return ;
    }
    if(r<=tree[root].mid)
            update(l,r,root<<1);
    else if(l>tree[root].mid)
            update(l,r,root<<1|1);
    else
    {
        update(l,tree[root].mid,root<<1);
        update(tree[root].mid+1,r,root<<1|1);
    }
    tree[root].sum=tree[root<<1].sum+tree[root<<1|1].sum;
    tree[root].flag=tree[root<<1].flag||tree[root<<1|1].flag;//如果子节点有未更新的则父节点必须更新
}
ll find(int l,int r, int root){
    if(tree[root].l==l && tree[root].r==r) return tree[root].sum;

    ll ans=0;

    if(r<=tree[root].mid)ans+=find(l,r,root<<1);
    else if(l>tree[root].mid)ans+=find(l,r,root<<1|1);
    else
        ans+=( find(l,tree[root].mid,root<<1)+ find(tree[root].mid+1,r,root<<1|1) );

    return ans;
}

int main(){
	int n, m, flag, x, y;
	int kase = 0;
	while(scanf("%d", &n) != EOF){
		printf("Case #%d:\n", ++kase);
		for(int i = 1; i <= n; ++i) scanf("%lld", &value[i]);

		build(1, n, 1);
		scanf("%d", &m);

		while(m--){
			scanf("%d%d%d", &flag, &x, &y);
			if(x > y) swap(x, y);
			if(flag == 1) printf("%lld\n", find(x, y, 1));
			else update(x, y, 1);
		}
		
		printf("\n");
	}
	return 0;
}