#include <iostream>  
#include <stdio.h>  
#include <string.h>  
using namespace std;  
   
int main()  
{  
    int t;  
    cin>>t;  
    long long a;  
    char s[111];  
    while(t--)  
    {  
        scanf("%lld",&a);  
        int g=0;  
        memset(s,0,sizeof(s));  
        while(a)  
        {  
            if(a&1)  
                s[g++]='1';  
            else  
                s[g++]='0';  
            a>>=1;  
        }  
        int m=0;  
        while(s[m]==0)  
        {  
            m++;  
        }   
        long long ans=1;  
        a=0;  
        for(int i=g-1;i>=m;i--)  
        {  
            a+=((s[i]-'0')*ans);  
            ans*=2;  
        }  
        cout<<a<<endl;  
   
    }  
    return 0;  
}  