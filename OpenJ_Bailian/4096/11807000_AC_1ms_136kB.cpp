#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char key[] = "12$\n";
const int MAXN = 510;
char array[MAXN];

int main()
{
	while(cin >> array)
	{
		for(int i = 0; i < strlen(array); ++i)
			printf("%c", key[array[i] - 'A']);
		printf("\n");
	}
}