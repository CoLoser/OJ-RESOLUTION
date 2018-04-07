#include <iostream>
#include <cstdio>
#include <algorithm> 
using namespace std;


const int MAXN = 2000002;
int arr[MAXN];


int main()
{
	int t;
	while(cin >> t && t)
	{
		for(int i = 0; i < t; ++i) cin >> arr[i];
		sort(arr, arr+t);
		for(int i = 0; i < t; ++i) printf("%d%c", arr[i], i == t - 1 ? '\n' : ' ');	
	}	
	return 0;
}