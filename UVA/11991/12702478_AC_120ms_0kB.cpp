#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAXM = 1000000;
vector<int> vec[MAXM + 1];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m, k, v, t;
	
	while(cin >> n >> m)
	{
		for(int i = 0; i < MAXM; ++i) vec[i].clear(); 
		for(int i = 0; i < n; ++i)
		{
			cin >> t;
			vec[t].push_back(i+1);
		}
		
		for(int i = 0; i < m; ++i)
		{
			cin >> k >> v;
			if(!vec[v].empty() && vec[v].size() >= k)
				cout << vec[v][k - 1] <<endl;
			else 
				cout << "0" <<endl;
		}
	}
	return 0;
}