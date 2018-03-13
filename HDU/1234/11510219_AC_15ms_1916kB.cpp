#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 10000;

struct Time{
	int hour;
	int minute;
	int second;
};
struct Activity{
	char ID[20];
	Time a, b;
};
Activity ac[maxn];

bool cmp0(Activity t1, Activity t2)
{
	if(t1.a.hour == t2.a.hour)
	{
		if(t1.a.minute == t2.a.minute) return t1.a.second < t2.a.second;
		else return t1.a.minute < t2.a.minute;
	}else return t1.a.hour < t2.a.hour;
}

bool cmp1(Activity t1, Activity t2)
{
	if(t1.b.hour == t2.b.hour)
	{
		if(t1.b.minute == t2.b.minute) return t1.b.second < t2.b.second;
		else return t1.b.minute < t2.b.minute;
	}else return t1.b.hour < t2.b.hour;
}

int main()
{
	int m;
	scanf("%d", &m);
	while(m--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
		{
			scanf("%s %d:%d:%d %d:%d:%d", ac[i].ID, &ac[i].a.hour, &ac[i].a.minute, &ac[i].a.second, &ac[i].b.hour, &ac[i].b.minute, &ac[i].b.second);
		}
		sort(ac, ac + n, cmp0);
		cout << ac[0].ID <<" ";
		sort(ac, ac + n, cmp1);
		cout << ac[n-1].ID <<endl;
	}
	return 0;
}