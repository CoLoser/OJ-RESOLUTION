#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;


const int MAXN = 100005;
int arr[MAXN*2];
int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	int a, t;
	memset(arr, 0, sizeof(arr));
	for(int i = 1; i <= MAXN; ++i) {
		int tmp = i, m = i;
		while(tmp) {
			m += tmp%10;
			tmp /= 10;
		}
		if(arr[m] == 0)
			arr[m] = i;
	}
	cin >> t;
	while(t--) {
		cin >> a;
		cout << arr[a] << endl;
	}
	return 0;
}