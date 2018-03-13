#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 55;
char key[maxn];
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> key;
		int len = strlen(key);
		for(int i = 0; i < len; i+=2)
		{
			swap(key[i], key[i+1]);
		}
		cout << key <<endl;
	}
}