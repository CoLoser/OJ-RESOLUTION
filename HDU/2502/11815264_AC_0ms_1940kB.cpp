#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 25;
int array[MAXN];

int main()
{
	array[1] = 1;
	for(int i = 2; i < MAXN; ++i)
		array[i] = (1 << (i - 1)) + (i - 1) * (1 << (i - 2));

	int t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		cout << array[n] <<endl;
	}
}