#include <iostream>
#include <cstdio>


using namespace std;

const int MAXN = 1000001;
int arr[MAXN];
const int MOD = 32767;
 
int main()
{
	arr[1] = 1;
	arr[2] = 2;
	
	for(int i = 3; i < MAXN; ++i) arr[i] = (2*arr[i-1] + arr[i-2]) % MOD;
	
	int t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		cout << arr[n] <<endl;
		}	
	return 0;
}
