#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 60;
typedef unsigned long long ull;
ull array[MAXN];

int main()
{
	int t, a, b;
	array[1] = array[2] = 1;
	for(int i = 3; i < MAXN; ++i)
		array[i] = array[i-1] + array[i-2];
	cin >> t;
	while(t--)
	{
		cin >> a >> b;
		cout << array[b - a + 1] <<endl;
	}
}