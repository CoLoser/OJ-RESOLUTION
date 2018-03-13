#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 102;

int arr[MAXN];

int main()
{
	int n;
	memset(arr, 0, sizeof(arr));
	while(cin >> n)
	{
		arr[n]++;
	}	
	
	int MAX = -1;
	
	for(int i = 0; i < MAXN; ++i) MAX = max(MAX, arr[i]);
	
	for(int i = 0; i < MAXN; ++i) if(arr[i] == MAX) cout << i <<endl;
	return 0;
}