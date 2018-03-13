#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define getHassVal(i, j) arr[i] + arr[j]

using namespace std;
const int MAXN = 1500000;
int arr[5000];
int hassMap[MAXN];

int main()
{
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF)
	{
		memset(hassMap, 0, sizeof(hassMap));
		for(int i = 0; i < n; ++i) cin >> arr[i];
		for(int i = 0; i < n; ++i)
			for(int j = i + 1; j < n; ++j) hassMap[getHassVal(i, j)]++;

		int flag = 0;
		for(int i = MAXN - 1; i > 0&&m>0; )
		{
			if(hassMap[i] == 0){i--; continue;}
			if(flag) cout << ' ' << i;
			else cout << i;
			flag = 1;
			hassMap[i]--;
			m--;
		}
		cout << endl;
	}
}