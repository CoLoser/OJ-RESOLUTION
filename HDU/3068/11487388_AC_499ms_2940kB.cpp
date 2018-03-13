#include<stdio.h>  
#include<string.h>  
#include<algorithm>  
using namespace std;  
#define maxn 110010*2  
  
int P[maxn];  
//(p.s. 可以看出，P[i]-1正好是原字符串中回文串的总长度）  
char s1[maxn];  
char s2[maxn];  
  
void manacher(char* s)  
{  
    int i,id=0,mx=0;  
    P[0]=0;                //P[0]位置没用  
    for(i=1;s[i];i++)      //对串进行线性扫描  
    {  
        if(mx > i)         //如果mx比当前i大，分为两种情况，详细致请看文章开头推荐的blog上的图示，非常给力的图  
            P[i] = min(P[2*id-i],mx-i);  
        else               //如果mx比i小，没有可以利用的信息，那么就只能从头开始匹配  
            P[i] = 1;  
        while(s[i+P[i]]==s[i-P[i]] )P[i]++;     //匹配  
        if(mx < P[i] + i) //坚持是否有更新mx以及id  
        {  
            mx = P[i] + i;  
            id = i;  
        }  
    }  
}  
  
  
void init()  
{  
    int i, j = 2;  
    s2[0] = '$', s2[1] = '#';  
  
    for(i=0;s1[i];i++)  
    {  
        s2[j++] = s1[i];  
        s2[j++] = '#';  
    }  
    s2[j] = '\0';  
}  
  
int main()  
{  
    while(scanf("%s",s1)!=EOF)  
    {  
        init();  
        manacher(s2);  
        int ans=0;  
        for(int i=1;s2[i]!='\0';i++)  
        {  
            ans=max(ans,P[i]);  
        }  
        printf("%d\n",ans-1);  
    }  
    return 0;  
}  