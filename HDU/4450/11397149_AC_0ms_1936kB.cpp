#include <iostream>

using namespace std;

int main()
{
	int n;
	while(scanf("%d", &n) != EOF && n)
	{
		int ans = 0;
		int t;
		while(n--)
		{
			cin >> t;
			ans += t*t;
		}
		cout << ans <<endl;
	}
}