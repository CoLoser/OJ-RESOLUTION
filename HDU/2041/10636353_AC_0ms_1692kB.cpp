#include<iostream>
using namespace std;
int main(){
	int N;
	cin >> N;
	for(int i = 0; i < N; i ++){
		int M;
		int count=0;
		int a[50];
		a[1]=1;
		a[2]=2;
		cin >> M;
		for(int j = 3; j < M; j ++){
			a[j]=a[j-1]+a[j-2];
		}
		cout<<a[M-1]<<endl;	
	} 
}