#include<iostream>  
#include<cstdio>  
#include<cstring>  
using namespace std;  
int main()  
{  
    int n,a[20],ce=1;  
    long long ans;  
    while(scanf("%d",&n)!=EOF&&n!=0)  
    {  
       long long maxn=0;  
       for(int i=1;i<=n;i++) scanf("%d",&a[i]);  
       for(int i=1;i<=n;i++)  
       {  
           for(int j=i;j<=n;j++)  
           {  
               ans=1;  
               for(int k=i;k<=j;k++)  
               {  
                   ans*=(long long)a[k];  
               }  
               maxn=max(maxn,ans);  
           }  
       }  
      printf("Case #%d: The maximum product is %lld.\n\n",ce++,maxn);  
    }  
   return 0;  
} 