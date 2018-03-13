#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int a, b, c;
	int ans;
	while(cin >> a >> b >> c)
	{
		ans = 0;
		for(int i = 0; i <= 1000; ++i)
			for(int j = 0; j <= 1000; j++)
				if(a*i + b*j == c)
				{
				 ans++; break;
				 }
		cout << ans <<endl;
	}
}