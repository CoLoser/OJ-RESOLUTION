#include <iostream>
#include <cstdio>

using namespace std;

const int BASE = 2;

int Count(int n)
{
	int ans = 0;
	while(n)
	{
		if(n%BASE == 1) ans ++;
		n/=BASE;
	}
	return ans;
}
int main()
{
	int n, t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		cout << Count(n) <<endl;
	}
}