#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n; 
	long long arr[51] = {0, 1, 2,};
	for(int i = 3; i < 51; ++i)
		arr[i] = arr[i-1] + arr[i-2];
	cin >> n;
	int a, b;
	while(scanf("%d%d", &a, &b) && n--){
		if(a > b) cout<< 0 <<endl;
		else cout<< arr[b - a]<<endl;
	}
	return 0;
}