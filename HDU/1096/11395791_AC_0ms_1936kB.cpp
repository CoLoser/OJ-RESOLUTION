#include <iostream>
#include <cstdio>


using namespace std;

int main()
{
	int n, m;
	int sum = 0;
	
	cin >> n;
	while(n --)
	{
		sum = 0;
		cin >> m;
		
		while(m--)
		{
			int t;
			cin >> t;
			sum += t;
		}
		cout << sum <<endl;
		if(n > 0) cout << "\n";
	}
	return 0;
}