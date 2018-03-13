#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 102;
int student[MAXN];

int main()
{
	int n;
	while(scanf("%d", &n) != EOF && n)
	{
		int key;
		memset(student, 0, sizeof(student));
		for(int i = 0; i < n; ++i)
		{
			scanf("%d", &key);
			student[key]++;
		}
		scanf("%d", &key);
		printf("%d\n", student[key]);
	}
}