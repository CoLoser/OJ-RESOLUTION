#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int a, b, t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &a, &b);
		int m = a^b;
		int cnt = 0;
		while(m)
		{
			m &= (m-1);
			cnt++;
		}
		printf("%d\n", cnt);
	}
}