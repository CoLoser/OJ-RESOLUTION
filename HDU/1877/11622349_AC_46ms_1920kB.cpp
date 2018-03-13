#include <iostream>
#include <cstdio>

using namespace std;

typedef unsigned int ui;

void DecToAny(ui n, int t)
{
	if(n == 0) return;
	DecToAny(n/t, t);
	printf("%d", n%t);
}
int main()
{
	int m;
	ui a, b;
	while(scanf("%d", &m) != EOF && m)
	{
		scanf("%d%d", &a, &b);
		if(a + b == 0) cout << 0;
		else DecToAny(a+b, m);
		cout << endl;
	}
	return 0;
}