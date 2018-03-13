#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1000000;

int arr[MAXN + 1];
 
int main()
{
	int t, m;
	
	cin >> t;
	
	for(int j = 1; j <= t; ++j)
	{
		scanf("%d", &m);
		for(int i = 0; i < m; ++i) scanf("%d", &arr[i]);
		
		int cnt = 0;
		int sum = 0;
		bool flag = true;
		
		for(int i = 0; i < m; ++i)
		{
			if(arr[i] > 0)
			{
				sum += arr[i];
				if(flag) cnt++, flag = false;
			}else if(arr[i] < 0) flag = true;
		}
		if(j != 1) printf("\n");
		printf("Case %d:\n", j);
		printf("%d %d\n", cnt, sum);
		//printf("\n");
	}
	return 0;
}