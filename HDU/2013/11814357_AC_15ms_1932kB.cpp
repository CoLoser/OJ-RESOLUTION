#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 30;
int array[MAXN + 1];

int main()
{
	array[0] = 1;
	for(int i = 1; i <= MAXN; ++i)
		array[i] = array[i - 1]*2 + 2;
	int n;
	while(cin >> n)
		cout << array[n-1] <<endl;
    return 0;
}