#include<iostream>
using namespace std;
int main(){
	int N;
	cin>>N;
	for(int i = 0; i < N; i ++){
		int a;
		int count=3;
		cin>>a;
		for(int j = 0; j < a; j ++){
			count=(count-1)*2;
		}
		cout<<count<<endl; 
	} 
}