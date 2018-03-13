#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	int h, m, s;
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int a1, b1, c1, a2, b2, c2;
		scanf("%d%d%d%d%d%d", &a1, &b1, &c1, &a2, &b2, &c2);
		s = (c1 + c2)%60;
		m = ((b1 + b2) + (c1 + c2)/60)%60;
		h = ((a1 + a2) + (b1 + b2 + (c1 + c2)/60)/60);
		printf("%d %d %d\n", h, m, s);
	}
	return 0;
}