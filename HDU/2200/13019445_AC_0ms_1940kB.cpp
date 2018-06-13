#include <iostream>

using namespace std;

typedef long long ll;

const int MAXN = 105;
ll arr[MAXN] = {0, 0, 1};

int main(){
	
	ll tmp = 4;
	for(int i = 3; i < MAXN; ++i){
		arr[i] = 2*arr[i - 1] + tmp - 1;
		tmp *= 2;
	}
	
	int n;
	while(cin >> n)
	{
		cout << arr[n] << endl;
	}
	return 0;
}
