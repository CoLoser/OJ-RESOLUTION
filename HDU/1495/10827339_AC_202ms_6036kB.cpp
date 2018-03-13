#include <iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
struct node
{
    int a,b,c,av,bv,cv,step;
};
int ss,n,m,ans;
int f[102][102][102];
int ok(int a,int b,int c)
{
    if (a==b && c==0) return 1;
    if (b==c && a==0) return 1;
    if (a==c && b==0) return 1;
    return 0;
}
void pour(int* a,int* b,int* av,int* bv,int* step)
{
    if (*a>0)
        {

            if (*a>=*bv-*b)
            {
                *a=*a-(*bv-*b);
                *b=*bv;
                *step=*step+1;
            } else
            {
                *b=*b+*a;
                *a=0;
                *step=*step+1;
            }
        }
    return;
}
int bfs()
{
    node p;
    queue<node> s;
    p.a=ss;
    p.b=0;
    p.c=0;
    p.av=ss;
    p.bv=n;
    p.cv=m;
    p.step=0;
    s.push(p);
    while(!s.empty())
    {
        node q=s.front();
        s.pop();
        //a->b
        p=q;
        pour(&p.a,&p.b,&p.av,&p.bv,&p.step);
        if(!f[p.a][p.b][p.c])
                {
                    s.push(p);
                    f[p.a][p.b][p.c]=1;
                }
                if(ok(p.a,p.b,p.c)) return p.step;
       //a->c
       p=q;
       pour(&p.a,&p.c,&p.av,&p.cv,&p.step);
       if(!f[p.a][p.b][p.c])
                {
                    s.push(p);
                    f[p.a][p.b][p.c]=1;
                }
                if(ok(p.a,p.b,p.c)) return p.step;
      //b->c
       p=q;
        pour(&p.b,&p.c,&p.bv,&p.cv,&p.step);
        if(!f[p.a][p.b][p.c])
                {
                    s.push(p);
                    f[p.a][p.b][p.c]=1;
                }
                if(ok(p.a,p.b,p.c)) return p.step;
       //b->a
        p=q;
        pour(&p.b,&p.a,&p.bv,&p.av,&p.step);
        if(!f[p.a][p.b][p.c])
                {
                    s.push(p);
                    f[p.a][p.b][p.c]=1;
                }
                if(ok(p.a,p.b,p.c)) return p.step;
       //c->a
        p=q;
        pour(&p.c,&p.a,&p.cv,&p.av,&p.step);
        if(!f[p.a][p.b][p.c])
                {
                    s.push(p);
                    f[p.a][p.b][p.c]=1;
                }
                if(ok(p.a,p.b,p.c)) return p.step;
        //c->b
        p=q;
        pour(&p.c,&p.b,&p.cv,&p.bv,&p.step);
        if(!f[p.a][p.b][p.c])
                {
                    s.push(p);
                    f[p.a][p.b][p.c]=1;
                }
                if(ok(p.a,p.b,p.c)) return p.step;
    }
   return -1;
}
int main()
{

    while(~scanf("%d%d%d",&ss,&n,&m))
    {
        if(ss==0 && n==0 && m==0) break;
        if (ss%2!=0)
        {
            printf("NO\n");
            continue;
        }
        memset(f,0,sizeof(f));
        ans=bfs();
        if (ans>0) printf("%d\n",ans);
            else printf("NO\n");
    }
    return 0;
}