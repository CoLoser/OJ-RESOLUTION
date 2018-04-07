#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 40;
char arr[MAXN];

int main()
{
	char from, to;
	while(cin >> arr >> from >> to)
	{
		for(int i = 0; i < strlen(arr); ++i) if(arr[i] == from) arr[i] = to;
		cout << arr <<endl;
	}
	return 0;
}