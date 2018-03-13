#include <cctype>
#include <cstdio>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	getchar();
	while(n--)
	{
		char c;
		int ans = 0;
		while(c=getchar())
		{
			if(c == '\n')break;
			if(isdigit(c)) ans ++;
		}
		printf("%d\n", ans);
	}
	return 0;
}