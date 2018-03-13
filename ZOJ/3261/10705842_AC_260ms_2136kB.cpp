#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
typedef long long ll;
int w,num,len;

const int N=12345;
int Power[N];
set< pair<int,int> > edge;
struct Query
{
    int op;
    int a,b;
    int ans;
    void Set_data(int opp,int aa,int bb)
    {
        op=opp;
        a=aa;
        b=bb;
    }
}query[50123];


int uset[N],mx[N];

int find_set(int x)
{
    if(uset[x]!=x)
    {
        int f=uset[x];
        uset[x]=find_set(uset[x]);
        mx[x]=max(mx[x],mx[f]);
    }
    return uset[x];
}

void union_set(int x,int y)
{
    int fx=find_set(x);
    int fy=find_set(y);
    if(fx==fy) return;
    if(mx[fy]>mx[fx]||(mx[fx]==mx[fy]&&fx>fy)) uset[fx]=fy;
    else uset[fy]=fx;

}


int main()
{
//  ios::sync_with_stdio(false);
    int n,m,q;
    int k = 0;
    while(~scanf("%d",&n))
    {
        if(k++)puts("");
        char op[10];
        int a,b;
        edge.clear();
        for(int i=0;i<n;i++) scanf("%d",&Power[i]);
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            if(a>b) swap(a,b);
            edge.insert(make_pair(a,b));
        }
        //离线处理 
        scanf("%d",&q);
        for(int i=0;i<q;i++)
        {
            scanf("%s",op); //I'm sb

            if(op[0]=='q')//query
            {
                scanf("%d",&a);
                query[i].Set_data(1,a,0);
            }
            else if(op[0]=='d') //destory 
            {
                scanf("%d%d",&a,&b);
                if(a>b)swap(a,b);  // WA了一次 
                edge.erase(make_pair(a,b));
                query[i].Set_data(2,a,b);
            }
        }
        for(int i=0;i<n;i++)
        {
            uset[i]=i;
            mx[i]=Power[i];
        }
        set< pair<int,int> >::iterator it;

        for(it=edge.begin();it!=edge.end();it++)
        {
            a=(*it).first;
            b=(*it).second;
            union_set(a,b);
        }
        for(int i=q-1;i>=0;i--)//倒着操作 
        {
            if(query[i].op==1) //query 
            {
                if(mx[find_set(query[i].a)] > Power[query[i].a])
                {
                    query[i].ans=uset[query[i].a]; //find the answer 
                }   
                else 
                {
                    query[i].ans= -1; //can not find the answer 
                }

            }
            else if(query[i].op==2)//destory , connect this operation
            {
                union_set(query[i].a,query[i].b);
            }
        }
        for(int i=0;i<q;i++)
        {
            if(query[i].op==1)//query 
            {
                printf("%d\n",query[i].ans);
            }               
        }

    }   
    return 0;
}