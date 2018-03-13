#include <iostream>
using namespace std;
int main(){
	//计算公式为:f(n)=2*n*n-n+1; 
	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		int m;
		cin>>m;
		cout<<(2*m*m-m+1)<<endl;
	}
}