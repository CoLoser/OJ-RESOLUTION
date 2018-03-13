#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e6+5;
 
int euler[N];
 
 
void Init()
{
     euler[1]=1;
     for(int i=2;i<N;i++)
       euler[i]=i;
     for(int i=2;i<N;i++)
        if(euler[i]==i)
           for(int j=i;j<N;j+=i)
              euler[j]=euler[j]/i*(i-1);
}
 
int main()
{
    Init();
    int n;
    while(cin>>n&&n)
    {
        long long ans=0;
        for(int i=2;i<=n;i++)
            ans+=euler[i];
        cout<<ans<<endl;
    }
}