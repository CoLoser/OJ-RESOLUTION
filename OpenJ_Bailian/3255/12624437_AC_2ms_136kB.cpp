#include <iostream>
#include <cstdio>

using namespace std;


void DecToAny(int n, int base)
{
	if(n == 0) return;
  	DecToAny(n/base, base);
  	printf("%d", n%base);
}
int main()
{
	int t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		if(n == 0) cout << 0;
		else DecToAny(n, 6);
		cout << endl;
	}
 } 