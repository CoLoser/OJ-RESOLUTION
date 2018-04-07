#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 12;
int arr[MAXN];
 
int main()
{
	int t = 0;
	for(int i = 1; i < MAXN; ++i)
		t += i*i*i, arr[i] = t;	
	int n;
	while(cin >> n)
		cout << arr[n] <<endl;
	return 0;
}