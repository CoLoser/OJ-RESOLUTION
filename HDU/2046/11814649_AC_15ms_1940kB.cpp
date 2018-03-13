#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;
const int MAXN = 55;

int main()
{
	ll array[MAXN] = {0, 1, 2};
	for(int i = 3; i < MAXN; ++i)
		array[i] = array[i-1] + array[i-2];
	int n;
	while(cin >> n)
	{
		cout << array[n] <<endl;
	}
}