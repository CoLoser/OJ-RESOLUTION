#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	long long arr[51]={1,1,2,};
	for(int i = 3; i < 51; i++){
		arr[i]=arr[i-1]+arr[i-2];
	}
	int N;
	while(scanf("%d",&N)!=EOF){
		cout<<arr[N]<<endl;
	}
	return 0;
}