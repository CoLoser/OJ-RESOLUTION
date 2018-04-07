#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int a, b;
	while(cin >> a >> b)
	{
		int c = a + b;
		int cnt = 0;
		
		while(c)
		{
			cnt ++;
			c /= 10;
		}
		cout << cnt <<endl; 
	}
	return 0;
}