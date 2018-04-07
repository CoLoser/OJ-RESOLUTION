#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int a, b, c, t;
	cin >> t;
	int  cnt = 0;
	
	while(t--)
	{
		cnt = 0;
		cin >> a >> b;
		
		c = a ^ b;
		
		while(c)
		{
			if(c & 1) cnt ++;
			c >>= 1;
		 } 
		 
		cout << cnt <<endl;
	}
 } 