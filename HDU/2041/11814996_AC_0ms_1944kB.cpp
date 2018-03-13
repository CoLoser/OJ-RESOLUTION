#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;
const int MAXN = 50;
ll array[MAXN];

int main()
{
	array[1] = 0;
	array[2] = 1;
	array[3] = 2;
	for(int i = 4; i < MAXN; ++i)
		array[i] = array[i - 1] + array[i - 2];

	int n, t;
	cin >> t;
	while(t --)
	{
		cin >> n;
		cout << array[n] <<endl;
	}
	return 0;
}