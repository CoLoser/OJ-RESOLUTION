#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define N 50005
using namespace std;
int value[N];
struct Tree
{
    int l;  //左端点
    int r;  //右端点
    int sum; //总数
} tree[N*4]; // 总线段的长度为N，开数组的话一般开到N 的四倍
void build(int root,int l,int r) // root表示根节点 ，他的区间范围【l,r】
{
    tree[root].l=l;
    tree[root].r=r;
    if(tree[root].l==tree[root].r) // 当左右端点相等时就是叶子节点
    {
        tree[root].sum=value[l];        // 赋除值
        return;                    //  递归出口
    }
    int mid=(l+r)/2;
    build(root<<1,l,mid);             // k<<1相等于k*2 即是他的左孩子
    build(root<<1|1,mid+1,r);         // k<<1|1 相当于k*2+1 ,即是他的右孩子
    tree[root].sum = tree[root<<1].sum + tree[root<<1|1].sum; // 父亲的sum  = 左孩子的sum  + 右孩子的sum
}
void update(int root,int pos,int val) // root是根节点，pos，val表示：我们要跟新在pos点出的值更新为val
{
    if(tree[root].l==tree[root].r)    //  如果是叶子节点，即是pos对应的位置
    {
        tree[root].sum=val;           //  更新操作
        return;                       //  递归出口
    }
    int mid=(tree[root].l + tree[root].r)/2;
    if(pos<=mid)                      //  如果pos点是在root对应的左孩子的话，就调用update(k<<1,pos,val); 在左孩子里找
        update(root<<1,pos,val);
    else
        update(root<<1|1,pos,val);
    tree[root].sum = tree[root<<1].sum + tree[root<<1|1].sum; // 父亲的sum  = 左孩子的sum  + 右孩子的sum
}

int query(int root,int L,int R) // root表示根节点，[L,R]表示要查询的区间
{
    if(L<=tree[root].l&&R>=tree[root].r)   // [L,R]要查询的区间 包含root节点表示的区间 直接返回root节点的sum值
        return tree[root].sum;
    int mid=(tree[root].l + tree[root].r)/2,ret=0;
    if(L<=mid) ret+=query(root<<1,L,R);        //  查询root节点的左孩子
    if(R>mid)  ret+=query(root<<1|1,L,R);      //  查询root节点的右?
    return ret;                             //  返回
}
int main()
{
    int t,n,ca=0;
    char s[10];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            scanf("%d",&value[i]);
        build(1,1,n);

        printf("Case %d:\n",++ca);
        while(scanf("%s",s),s[0]!='E')
        {
            int a,b;
            scanf("%d%d",&a,&b);
            if(s[0]=='Q')
            {
                if(a>b)
                    swap(a,b);
                printf("%d\n",query(1,a,b));
            }
            if(s[0]=='A')
                value[a]+=b,update(1,a,value[a]);
            if(s[0]=='S')
                value[a]-=b,update(1,a,value[a]);
        }
    }
    return 0;
}