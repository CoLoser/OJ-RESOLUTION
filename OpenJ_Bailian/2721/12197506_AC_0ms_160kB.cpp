#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 100;
char arr1[MAXN];
char arr2[MAXN];

int main()
{
	gets(arr1);
	gets(arr2);
	for(int i = 0; i < strlen(arr1); ++i) if(isupper(arr1[i])) arr1[i] += 32;
	for(int i = 0; i < strlen(arr2); ++i) if(isupper(arr2[i])) arr2[i] += 32;
	int flag = strcmp(arr1, arr2);
	printf("%c\n", flag == 0 ? '=' : (flag > 0 ? '>' : '<'));
	return 0;
}