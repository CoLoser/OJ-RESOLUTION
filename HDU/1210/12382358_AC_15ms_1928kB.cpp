#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		int cnt = 0;
		int cur = 1;
		while(1)
		{
			cnt ++;
			if(cur <= n) cur *= 2;
			else cur = (cur - n)*2 - 1;
			
			if(cur == 1) break;
		}
		cout << cnt <<endl;
	}
	return 0;
}