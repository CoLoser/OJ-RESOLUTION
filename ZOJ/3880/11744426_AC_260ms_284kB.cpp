#include <iostream>
using namespace std;

int main()
{
	int t;
	int n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		int m;
		int cnt = 0;
		while(n--)
		{
			cin >> m;
			if(m > 6000) cnt ++;
		}
		cout << cnt <<endl;
	}
	return 0;
}