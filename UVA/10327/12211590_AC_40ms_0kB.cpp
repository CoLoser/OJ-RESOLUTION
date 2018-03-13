#include <iostream>
#include <cstdio>

//找逆序对
using namespace std;

const int MAXN = 1001;
int arr[MAXN];

int main()
{
	int t;
	while(scanf("%d", &t) != EOF)
	{
		for(int i = 0; i < t; ++i) cin >> arr[i];
		
		int flag = 1;
		int ans = 0;
		
		while(flag)
		{
			flag = 0;
			
			for(int i = 0; i < t - 1; ++i)
				if(arr[i] > arr[i+1]) swap(arr[i], arr[i+1]), flag = 1, ans ++;
		}
		
		printf("Minimum exchange operations : %d\n", ans);
	}
	return 0;
}