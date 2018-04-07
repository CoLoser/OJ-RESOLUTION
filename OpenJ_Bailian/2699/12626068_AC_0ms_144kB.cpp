#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 100;
int arr[MAXN];
 
int main()
{
	int t, n;
	memset(arr, 0, sizeof(arr));
	for(int i = 10; i < 100; ++i)
	{
		int tmp = i/10 + i%10;
		if(i%tmp == 0) arr[i] = 1;	
	}	
	while(cin >> t){
		for(int i = 10; i <= t; ++i)
		{
			if(arr[i]) cout << i <<endl;
		}
	} 
	return 0;
} 