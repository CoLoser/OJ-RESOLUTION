#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int t, sum = 1, x;
	while(scanf("%d", &t) != EOF)
	{
		sum = 1;
		while(t--)
		{
			cin>>x;
			if(x%2 == 1) sum *= x;
		}
		cout << sum <<endl;
	}
	return 0;
}