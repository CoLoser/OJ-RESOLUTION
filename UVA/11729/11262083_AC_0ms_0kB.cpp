#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 1005;
struct Job{
	int b, j;
	bool operator < (const Job& x) const{
		return j > x.j;
	}
};
vector<Job> job;
int main()
{
	int n;
	int b, j;
	int kase = 0;
	while(scanf("%d", &n) != EOF && n)
	{
		job.clear();
		int ans = 0;
		int start = 0;
		for(int i = 0; i < n; ++i)
		{
			scanf("%d%d", &b, &j);
			job.push_back((Job){b, j});
		}
		sort(job.begin(), job.end());
		printf("Case %d:", ++kase);

		for(vector<Job>::iterator it = job.begin(); it != job.end(); ++it)
		{
			start += (*it).b;
			ans = max(ans, start + (*it).j);

		}
		printf(" %d\n", ans);
	}
	return 0;
}