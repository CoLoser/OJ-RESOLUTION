#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 205;
char arr[MAXN];

int main()
{
	int t;
	while(cin >> t && t)
	{
		cin >> arr;
		int len = strlen(arr);
		for(int i = 0; i < t; ++i)
		{
			for(int j = 0; j < len/t; ++j)
			{
				cout << arr[j*t + (j%2 ? t-i-1 : i)];
			}
		}
		cout << endl;
	}
	return 0;
}