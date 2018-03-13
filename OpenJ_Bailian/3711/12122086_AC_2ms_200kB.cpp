#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 33;
char key1[MAXN*2];
char key2[MAXN*2];

char arr1[MAXN];
char arr2[MAXN];

int main()
{
	while(cin >> arr1 >> arr2)
	{
		strcat(key1, arr1);
		strcat(key1, arr1);
		strcat(key2, arr2);
		strcat(key2, arr2);
		
		bool flag = strlen(arr1) >= strlen(arr2) ? strstr(key1, arr2) : strstr(key2, arr1);
		printf("%s\n", flag ? "true" : "false");
	}
	return 0;
}