#include<stdio.h>  
#include<string.h>  
#include<algorithm>  
using namespace std;  
int rale[666],pre[666];  
struct aa  
{  
    int u,v;  
    int val;  
} save[2333];  
int findboss(int x)  
{  
    if(x==pre[x])  
        return x;  
    else  
    {  
        int k=pre[x];  
        pre[x]=findboss(pre[x]);  
        rale[x]=(rale[x]+rale[k])%3;  
        return pre[x];  
    }  
}  
int wrong[666];  
int main()  
{  
    int n,m;  
    while(scanf("%d%d",&n,&m)!=EOF)  
    {  
        memset(wrong,-1,sizeof(wrong));  
        getchar();  
        for(int i=0; i<m; i++)  
        {  
            char w;  
            scanf("%d",&save[i].u);  
            scanf("%c",&w);  
            scanf("%d",&save[i].v);  
            getchar();  
            if(w=='<')  
                save[i].val=1;  
            else if(w=='>')  
                save[i].val=2;  
            else  
                save[i].val=0;  
        }  
        for(int i=0; i<n; i++)  
        {  
            for(int j=0; j<n; j++)//初始化  
            {  
                pre[j]=j;  
                rale[j]=0;  
            }  
            for(int j=0; j<m; j++)  
            {  
                int a=save[j].u,b=save[j].v,c=save[j].val;  
                if(a==i||b==i)  
                    continue;  
                int aa=findboss(a),bb=findboss(b);  
                if(aa==bb)  
                {  
                    int r=(rale[b]-rale[a]+3)%3;  
                    if(r!=c)  
                    {  
                        wrong[i]=j+1;  
                        break;  
                    }  
                }  
                else  
                {  
                    pre[bb]=aa;  
                    rale[bb]=(rale[a]-rale[b]+3+c)%3;  
                }  
            }  
        }  
        int cnt=0,a1=0,a2=0;  
        for(int i=0; i<n; i++)  
        {  
            if(wrong[i]==-1)  
            {  
                cnt++;  
                a1=i;  
            }  
            a2=max(a2,wrong[i]);  
        }  
        if(cnt==0) puts("Impossible");  
        else if(cnt>1) puts("Can not determine");  
        else printf("Player %d can be determined to be the judge after %d lines\n",a1,a2);  
  
    }  
  	return 0;
}  