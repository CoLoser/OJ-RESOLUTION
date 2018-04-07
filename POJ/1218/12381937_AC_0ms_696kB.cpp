#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 105;
int arr[MAXN];

int main(){
	int t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		memset(arr, 0, sizeof(arr));

		for(int i = 2; i <= n; ++i)
		{
			for(int j = i; j <= n; ++j)
			{
				if(j % i == 0) arr[j] = 1 - arr[j];
			}
		}
		int cnt = 0;
		for(int i = 1; i <= n; ++i) if(arr[i] == 0) cnt ++;
		cout << cnt <<endl;
	}    
}