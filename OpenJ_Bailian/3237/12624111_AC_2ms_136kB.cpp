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
		if(n % 2) printf("0 0\n");
		else{
			printf("%d %d\n", n/4 + (n%4)/2, n/2);
		}
	}
	return 0;
}