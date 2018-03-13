#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	long long arr[60]={0,3,6,6};
	for(int i = 4; i < 60; i++){
		arr[i]=arr[i-1]+2*arr[i-2];
	}
	int N;
	while(scanf("%d",&N)!=EOF){
		printf("%I64d\n",arr[N]);
	}
	return 0;		
}