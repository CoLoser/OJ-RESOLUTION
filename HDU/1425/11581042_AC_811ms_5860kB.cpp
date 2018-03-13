#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<stack>
#include<ctime>
#include<cstdlib>
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
using namespace std;
#define M 500000
int hashMap[M*2+1];
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        int a,i,j,k=0;
        mem(hashMap,0);
        for(i=0; i<n; i++)
        {
            scanf("%d",&a);
            hashMap[M+a]=1;    //和上面那题差不多，+M的原因就是防止下标为负的情况
        }
        for(i=M*2; i>=0&&m>0; i--)
        {
            if(!hashMap[i]) continue;
            if(k) cout<<' '<<i-M;
            else cout<<i-M;
            k=1;
            m--;
        }
        cout<<endl;
    }
    return 0;
}