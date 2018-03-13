#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n;
	while(cin >> n)
	{
		if(n % 2 == 0)
			printf("%d %d\n", n/4 + n % 4 /2, n/2);
        else
            printf("0 0\n");
	}
}