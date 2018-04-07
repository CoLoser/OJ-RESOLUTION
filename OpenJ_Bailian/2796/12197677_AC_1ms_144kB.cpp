#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int a, sum = 0, b;
	cin >> a;
	for(int i = 0; i < 5; ++i)
	{
		cin >> b;
		if(b < a) sum += b;
	}
	cout << sum <<endl;
}