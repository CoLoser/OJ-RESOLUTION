#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxm = 10005;
const int maxn = 1000005;

struct K_M_P{
	char pattern[maxm];
	char target[maxn];
	int next[maxm];
	int sum;
};
K_M_P kmp;

void KMP()
{
	kmp.sum = 0;
	int pattern_len = strlen(kmp.pattern);
	int target_len = strlen(kmp.target);
	
	int i = 0;
	int j = -1;
	//计算next数组
	kmp.next[0] = -1;
	while(i < pattern_len)
    {
        if(j ==-1 || kmp.pattern[i] == kmp.pattern[j])
        {
            kmp.next[++i] = ++j;
        }
        else
            j=kmp.next[j];
    }
    
    
	//kmp;
	j = 0;
	i = 0;
	while(i < target_len && j < pattern_len){
        if(j == -1 || kmp.pattern[j] == kmp.target[i])
        {
            i++;
            j++;
        }
        else j = kmp.next[j];
        if(j == pattern_len){
        	kmp.sum++;
        	j = kmp.next[j];
		} 
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	while(n --)
	{
		scanf("%s", kmp.pattern);
		scanf("%s", kmp.target);
		KMP();
		printf("%d\n", kmp.sum);
	}
}