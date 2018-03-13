#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<math.h>
#include<queue>
using namespace std;
#define INF 0x3f3f3f3f
#define ll long long
#define met(a,b) memset(a,b,sizeof(a))
#define N 109
int vis[N][N];
char str[N][N];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int k,n,m;
struct node
{
    int x,y,temp;
}a[N];///统计干草的坐标
int pan()///判断干草是否都能被点燃
{
    int x,y;
    for(int i=0;i<k;i++)
    {
        x=a[i].x;y=a[i].y;
        if(!vis[x][y])
            return 0;
    }
    return 1;
}
int bfs(node a,node b)
{
    int team=0;
    met(vis,0);
    queue<node>Q;
    node q,p;
    Q.push(a);Q.push(b);
    vis[a.x][a.y]=1;vis[b.x][b.y]=1;
    while(Q.size())
    {
        q=Q.front();
        Q.pop();
        for(int i=0;i<4;i++)
        {
            p.x=q.x+dir[i][0];
            p.y=q.y+dir[i][1];
            p.temp=q.temp+1;
            if(p.x>=0 && p.x<n&& p.y>=0 && p.y<m && str[p.x][p.y]=='#' && !vis[p.x][p.y])
            {
                vis[p.x][p.y]=1;
                team=max(team,p.temp);
                Q.push(p);
            }
        }
    }
    if(pan())
        return team;
    else
        return INF;
}
int main()
{
    int t,con=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%s",str[i]);
        k=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(str[i][j]=='#')
                {
                    a[k].x=i;
                    a[k].y=j;
                    a[k++].temp=0;
                }
            }
        }
        int ans=INF;
        for(int i=0;i<k;i++)
        {
            for(int j=i;j<k;j++)
            {
                ans=min(bfs(a[i],a[j]),ans);
            }
        }
        printf("Case %d: ",con++);
        if(ans==INF)
            printf("-1\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}