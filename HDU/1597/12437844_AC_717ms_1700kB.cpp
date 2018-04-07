#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		
		int i = 1;
		while(n > i)
		{
			n -= i;
			i ++;
		}
		
		n %= 9;
		n = (n ? n : n = 9);
		
		cout << n <<endl;
	}
}