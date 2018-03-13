#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 1001;
struct _Node{
	int num;
	int time;
	int fine;
};

bool cmp(_Node rhs1, _Node rhs2)
{
	double rate1 = (double)(rhs1.fine*1.0/rhs1.time);
	double rate2 = (double)(rhs2.fine*1.0/rhs2.time);
	//cout << rate1 << " " << rate2 << endl;
	return (fabs(rate1 - rate2) <= 1e-6) ? rhs1.num < rhs2.num : rate1 > rate2;
}

_Node arr[MAXN];

int main()
{
	int t, n, flag = 0;
	cin >> t;
	while(t--)
	{
		if(flag++)printf("\n");
		cin >> n;
		for(int i = 0; i < n; ++i)
		{
			arr[i].num = i + 1;
			scanf("%d%d", &arr[i].time, &arr[i].fine);
		}
		
		sort(arr, arr + n, cmp);
		
		for(int i = 0; i < n; ++i) printf("%d%c", arr[i].num, i == n - 1 ? '\n' : ' ');
	}
	return 0;
}