#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 10000;
char arr[maxn];

int main()
{
	while(scanf("%s", arr) != EOF)
	{
		sort(arr, arr + strlen(arr));
		for(int i = 0; i < strlen(arr); ++i) printf("%c%c", arr[i], i == strlen(arr) - 1? '\n' : ' ');
	}
}