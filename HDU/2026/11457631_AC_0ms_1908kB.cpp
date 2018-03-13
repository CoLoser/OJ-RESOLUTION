#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 105;
char arr[maxn];
int x = 'a' - 'A';
int main()
{
	while(gets(arr))
	{
		arr[0] -= x;
		for(int i = 0; i < strlen(arr); ++i)
		{
			if(arr[i-1] == ' '&&isalpha(arr[i])) arr[i] -= x;
		}
		cout << arr <<endl;
	}
}