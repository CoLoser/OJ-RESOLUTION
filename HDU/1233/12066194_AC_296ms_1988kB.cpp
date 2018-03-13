#include <stdio.h>  
#include <string.h>  
#include <iostream>  
#include <algorithm>  
using namespace std;  
int n,a[10005];  
struct note  
{  
    int x,y,z;  
};  
int find(int x)  
{  
    if(a[x]==x)  
        return x;  
    return a[x]=find(a[x]);  
}  
void inistic()  
{  
    for(int i=0;i<=n;i++)  
    {  
        a[i]=i;  
    }  
}  
void un(int x,int y)  
{  
    x=find(x);  
    y=find(y);  
    if(x!=y)  
      a[x]=y;  
}  
int cmp(note a,note b)  
{  
    return a.z<b.z;  
}  
int main()  
{  
    note ab[10005];  
    while(~scanf("%d",&n))  
    {  
        if(!n)  
           break;  
        inistic();  
        for(int i=0;i<(n-1)*n/2;i++)  
            scanf("%d%d%d",&ab[i].x,&ab[i].y,&ab[i].z);  
        sort(ab,ab+n*(n-1)/2,cmp);  
        int sum=0;  
        int count=0;  
        for(int i=0;i<n*(n-1)/2;i++)  
        {  
            if(find(ab[i].x)!=find(ab[i].y))  
            {  
                un(ab[i].x,ab[i].y);  
                sum+=ab[i].z;  
            }  
        }  
        printf("%d\n",sum);  
    }  
    return 0;  
}  