#include <iostream>

using namespace std;

const int MAXN = 33;
char bit[MAXN];

void set(int n, int t)
{
	for(int i = 0; i < 8; ++i)
	{
		bit[n--] = t%2 + '0';
		t /= 2;
	}
}
int main()
{
	int p1, p2, p3, p4;
	while(scanf("%d", &p1) != EOF && p1 != -1)
	{
		scanf(".%d.%d.%d", &p2, &p3, &p4);
		
		set(7, p1);
		set(15, p2);
		set(23, p3);
		set(31, p4);
		
		printf("%s\n", bit);
	}
}