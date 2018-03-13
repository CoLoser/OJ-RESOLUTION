#include <iostream>
#include <cstdio>

using namespace std;

void DecToBin(int n)
{
	if(n == 0) return;
	DecToBin(n/2);
	printf("%d", n%2);
}
int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		DecToBin(n);
		cout << endl;
	}
		
	return 0;
}