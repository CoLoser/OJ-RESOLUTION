#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 60;
int array[MAXN];

int main()
{
	int n;
	for(int i = 1; i <= MAXN; ++i)
	{
		if(i <= 4) array[i] = i;
		else array[i] = array[i-1] + array[i-3];
	}
	while(cin >>n)
	{
		if(n == 0) break;
		else cout << array[n] <<endl;
	}
}