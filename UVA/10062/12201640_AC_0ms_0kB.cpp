#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct _Node{
	char key;
	int cnt;
};

const int MAXN = 1001;
_Node arr[129];
char key[MAXN];

bool cmp(_Node rhs1, _Node rhs2)
{
	return rhs1.cnt != rhs2.cnt ? rhs1.cnt < rhs2.cnt : rhs1.key > rhs2.key;
}

void init()
{
	for(int i = 0; i < 129; ++i)
	{
		arr[i].key = i;
		arr[i].cnt = 0;
	}
}
int main()
{
	int flag = 0;
	while(cin.getline(key, 1001))
	{
		if(flag++) printf("\n");
		init();
		for(int i = 0; i < strlen(key); ++i) arr[key[i]].cnt++, arr[key[i]].key = key[i];
		sort(arr, arr+128, cmp);
		for(int i = 0; i < 129; ++i) if(arr[i].cnt != 0) printf("%d %d\n", arr[i].key, arr[i].cnt);
	}
	return 0;
}