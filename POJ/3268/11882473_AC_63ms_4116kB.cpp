#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<iomanip>
using namespace std;
//有向图各点到star和star到各点最短路
const int maxn=1005;
const int INF=0x3f3f3f3f;
int map[maxn][maxn];//有向图
int dis_to[maxn];//star到各点最短距离
int dis_from[maxn];//各点到star最短距离
bool vis_to[maxn];
bool vis_from[maxn];
int N;//图大小
void Dijkstra(int star)
{
    for(int i=1; i<=N; i++)
    {
        dis_to[i]=map[star][i];//star到各点
        dis_from[i]=map[i][star];//各点到star
        vis_from[i]=vis_to[i]=0;
    }
    vis_from[star]=vis_to[star]=1;
    for(int i=1; i<N; i++) //star到各点最短路
    {
        int minn=INF;
        int point;
        for(int j=1; j<=N; j++)
            if(vis_to[j]==0&&dis_to[j]<minn)
            {
                minn=dis_to[j];
                point=j;
            }
        if(minn==INF)
            break;
        vis_to[point]=1;
        for(int j=1; j<=N; j++)
            if(vis_to[j]==0&&dis_to[j]>dis_to[point]+map[point][j])
                dis_to[j]=dis_to[point]+map[point][j];
    }
    for(int i=1; i<N; i++) //各点到star最短路
    {
        int minn=INF;
        int point;
        for(int j=1; j<=N; j++)
            if(vis_from[j]==0&&dis_from[j]<minn)
            {
                minn=dis_from[j];
                point=j;
            }
        if(minn==INF)
            break;
        vis_from[point]=1;
        for(int j=1; j<=N; j++)
            if(vis_from[j]==0&&dis_from[j]>dis_from[point]+map[j][point])
                dis_from[j]=dis_from[point]+map[j][point];
    }
}
int main()
{
    int M,X;
    scanf("%d%d%d",&N,&M,&X);
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            i==j?map[i][j]=0:map[i][j]=INF;
    while(M--)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        if(map[u][v]>w)
            map[u][v]=w;//有向图
    }
    Dijkstra(X);
    int max_num=-1;
    for(int i=1; i<=N; i++)
        if(dis_to[i]+dis_from[i]>max_num)
            max_num=dis_to[i]+dis_from[i];
    printf("%d\n",max_num);
    return 0;
}