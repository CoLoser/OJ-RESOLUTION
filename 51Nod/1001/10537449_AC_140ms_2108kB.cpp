#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int INF=1<<30;

int a[50010];

int main(){
    int n;long long k;
    cin>>k>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    /*for(int i=0;i<n;i++)
    cout<<a[i]<<" ";*/
    int t=n-1,i=0,ans=0;
    while(1){
        if(a[i]+a[t]==k&&i<t){
            cout<<a[i]<<" "<<a[t]<<endl;
            ans++;
            i++;
        }
        else if(a[i]+a[t]>k){
            t--;
        }
        else if(a[i]+a[t]<k){
            i++;
        }
        if(i>=t)
        break;
    }
    if(ans==0){
        cout<<"No Solution"<<endl;
    }
    return 0;
}