#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
const int MAXN = 1e6;
bool visit[MAXN];
int prime[MAXN];
using namespace std;
void solve()
{
	memset(prime, 0, sizeof(prime));
	memset(visit, 0, sizeof(visit));
	visit[0] = 1;
	visit[1] = 1;
	for(int i = 2; i < sqrt(MAXN); ++i) if(!visit[i])
		for(int j = i * i; j < MAXN; j += i) visit[j] = 1;
		
	int cnt = 0;
	for(int i = 0; i < MAXN; ++i)
	{
		if(!visit[i]) cnt++;
		prime[i] = cnt;
	}
}


int main()
{
	int n;
	solve();
	while(cin >> n)
		cout << prime[n] <<endl;
}