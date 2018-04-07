#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 60;
long long arr[MAXN];

int main(){
	int n;
	arr[0] = 0;
	arr[1] = 1;
	for(int i = 2; i < MAXN; ++i) arr[i] = arr[i-1] + arr[i-2];
	
	while(cin >> n && n != -1)
		cout << arr[n] <<endl;
	return 0; 
}