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

void build(int l,int r, int id){
    tree[id].l=l;  tree[id].r=r;  tree[id].mid=(l+r)>>1;
    tree[id].flag=1;

    if(l==r)
    {
        tree[id].sum=value[l];
        if(value[l]<=1) tree[id].flag=0;
        return ;
    }

    build(l,tree[id].mid,id<<1);
    build(tree[id].mid+1,r,id<<1|1);
    tree[id].sum=tree[id<<1].sum+tree[id<<1|1].sum;
    tree[id].flag=tree[id<<1].flag || tree[id<<1|1].flag;
}
void update(int l,int r,int id)
{
    if(tree[id].flag==0)return;
    if(tree[id].l==tree[id].r && tree[id].l==l &&tree[id].r==r)
    {
        tree[id].sum=(ll)sqrt(1.0*tree[id].sum);
        if(tree[id].sum<=1) tree[id].flag=0; //标记为0  就不找了
        return ;
    }
    if(r<=tree[id].mid)
            update(l,r,id<<1);
    else if(l>tree[id].mid)
            update(l,r,id<<1|1);
    else
    {
        update(l,tree[id].mid,id<<1);
        update(tree[id].mid+1,r,id<<1|1);
    }
    tree[id].sum=tree[id<<1].sum+tree[id<<1|1].sum;
    tree[id].flag=tree[id<<1].flag||tree[id<<1|1].flag;//如果子节点有未更新的则父节点必须更新
}
ll find(int l,int r, int id){
    if(tree[id].l==l && tree[id].r==r) return tree[id].sum;

    ll ans=0;

    if(r<=tree[id].mid)ans+=find(l,r,id<<1);
    else if(l>tree[id].mid)ans+=find(l,r,id<<1|1);
    else
        ans+=( find(l,tree[id].mid,id<<1)+ find(tree[id].mid+1,r,id<<1|1) );

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