#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	long long arr[51];
	arr[1]=1;
	arr[2]=2;
	int N,a,b;
	cin>>N;
	for(int j = 3; j < 51; j++)
	 	arr[j]=arr[j-1]+arr[j-2];
	while(N-- && scanf("%d%d",&a,&b) != EOF){
		cout<<((a>b)?0:arr[b-a])<<endl;
	}
	return 0;	
} 