#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 25;
char arr[MAXN];
int ai[MAXN];

int main()
{
	int cnt = 0;
	while(cin.getline(arr, 21))
	{
		cnt = 0;
		for(int i = 0; i < strlen(arr); ++i)
			if(isdigit(arr[i])) ai[cnt++] = arr[i] - '0';
		sort(ai, ai+cnt);
		for(int i = 0; i < cnt; ++i)
			printf("%4d", ai[i]);
		cout<<endl;
	}
	return 0;
}