#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int a, b, c;
	while(scanf("%d%d%d", &a, &b, &c) != EOF)
	{
		int cnt = 0;
		for(int i = 0; i <= 1000; ++i)
			for(int j = 0; j <= 1000; ++j)
				if(a*i + b*j == c) cnt++;

		printf("%d\n", cnt);
	}
	return 0;
}