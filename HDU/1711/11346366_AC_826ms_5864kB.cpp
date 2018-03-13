#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 1000005;
const int maxm = 10005;

struct K_M_P{
	int target[maxn];
	int pattern[maxm];
	int next[maxm];
	int target_len;
	int pattren_len;
};
K_M_P kmp;


int KMP(){
	
	//预处理计算next数组;
	kmp.next[0] = 0;
	kmp.next[1] = 0;
	for(int i = 1; i < kmp.pattren_len; ++i)
	{
		int j = kmp.next[i];
		while(j && kmp.pattern[i] != kmp.pattern[j]) j = kmp.next[j];
		kmp.next[i+1] = kmp.pattern[i] == kmp.pattern[j] ? j + 1 : 0;
	}

	//kmp
	int j = 0;
	for(int i = 0; i < kmp.target_len; ++i)
	{
		while(j && kmp.pattern[j] != kmp.target[i]) j = kmp.next[j];
		if(kmp.pattern[j] == kmp.target[i]) j++;
		if(j == kmp.pattren_len)
		{
		 	printf("%d\n", i - kmp.pattren_len + 1 + 1);
		 	return -1;
		}
	}
	return 1;
}

int main()
{
	int n, m, t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &n, &m);
		kmp.target_len = n;
		kmp.pattren_len = m;
		for(int i = 0; i < n; ++i) scanf("%d", &kmp.target[i]);
		for(int i = 0; i < m; ++i) scanf("%d", &kmp.pattern[i]);
		if(KMP() == 1) printf("-1\n");
	}
	return 0;
}