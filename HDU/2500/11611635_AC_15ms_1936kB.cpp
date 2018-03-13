#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int t, n;
	scanf("%d", &t);
	while(t--)
	{
		cin >> n;
		for(int i = 0; i < 3*n; ++i)
		{
			for(int j = 0; j < n; ++j)
				printf("HDU");
			printf("\n");
		}
	}
	return 0;
}