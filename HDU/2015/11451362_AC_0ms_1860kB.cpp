#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> vec;

int main()
{
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF)
	{
		int ans = 0;
		int t = 0;
		vec.clear();
		for(int i = 2; i <= 2*n; i+=2)
		{
			
			ans += i;
			t++;
			if(t == m)
			{
				vec.push_back(ans);
				t = 0;
				ans = 0;
			}
		}
		if(ans != 0) vec.push_back(ans);
		vector<int>::iterator it;
		for( it = vec.begin(); it != vec.end()-1; ++it)
		{
			printf("%d ", *it/m);
		}
		if(t == 0)
			printf("%d\n", *it/m);
		else
			printf("%d\n", *it/t);
	}
	return 0;
}