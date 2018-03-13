#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <sstream>
using namespace std;

typedef long long ll;
const int maxn = 105;
int arr[maxn];
string s;
int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a%b);
}
int main(){
	int n;
	int idx = 0;
	int maxgcd = -1;
	scanf("%d", &n);
	getchar();
	while(n--){
		idx = 0;
		maxgcd = -1;
		getline(cin, s);
		stringstream ss(s);
		while(ss >> arr[idx]) idx++;
		//for(int i = 0; i < idx; ++i) cout << arr[i] <<endl;
		for(int i = 0; i < idx - 1; ++i)
			for(int j = i + 1; j < idx; ++j) maxgcd = max(gcd(arr[i], arr[j]), maxgcd);

		printf("%d\n", maxgcd);
	}
	return 0;
}