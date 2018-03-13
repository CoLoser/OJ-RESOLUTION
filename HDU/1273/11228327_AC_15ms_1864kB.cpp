#include <iostream>

using namespace std;

int main()
{
	int t;
	while(scanf("%d", &t) != EOF && t)
	{
		printf("%d\n", (t-1)/2);
	}
}