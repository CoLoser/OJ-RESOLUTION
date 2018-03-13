#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int t;
	while(scanf("%d", &t) != EOF)
	{
		if(t%3 == 0 && t%5 == 0 && t%7 == 0) printf("3 5 7\n");
		else if(t%3 == 0 && t%5 == 0) printf("3 5\n");
		else if(t%3 == 0 && t%7 == 0) printf("3 7\n");
		else if(t%5 == 0 && t%7 == 0) printf("5 7\n");
		else if(t%3 == 0) printf("3\n");
		else if(t%5 == 0) printf("5\n");
		else if(t%7 == 0) printf("7\n");
		else printf("n\n");
	}
}