#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;
char a[20];
ll pow(int x, int p, int y)
{
 	if(y == 0) return p;
	pow(x, p*x, y-1);
}
ll AnyToDec(char a[], int t, int len)
{
	ll ans = 0;
	for(int i = len - 1; i >= 0; --i)
		ans += (a[i] - '0') * pow(t, 1, len - i - 1);
	return ans;
}

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		ll ans = 0;
		while(n --)
		{
			char key;
			int idx = 0, t;
			getchar();
			while((key = getchar()) != EOF && key != '(')
				a[idx++] = key;
			scanf("%d)", &t);
			ans += AnyToDec(a, t, idx);
		}
		printf("%lld\n", ans);
	}
	return 0;
}