#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

int num[1050];

int main()
{
	int t, n, k;
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	scanf("%d", &t);
	
	while(t--)
	{
		scanf("%d%d", &n, &k);
		for(int i = 0; i < n; ++i) scanf("%d", &num[i]);
		
		for(int i = 0; i < k; ++i) next_permutation(num, num + n);
		copy(num, num+n-1, ostream_iterator<int>(cout, " "));
		cout << num[n-1] <<endl;
		//for(int i = 0; i < n; ++i) printf("%d%c", num[i],  i == n - 1 ? '\n' : ' ');
	}		
	return 0;
}