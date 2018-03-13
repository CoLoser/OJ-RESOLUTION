#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 1005;

struct K_M_P{
	char pattern[maxn];
	char target[maxn];
	int next[maxn];
	int ans;
	
	int pattern_len(){
		return strlen(pattern);
	}
	int target_len(){
		return strlen(target);
	}
	
};

K_M_P kmp;

void KMP(){
	kmp.ans = 0;

 //计算next数组

	kmp.next[0] = -1;
	int i = 0;
	int j = -1;

	while(i < kmp.pattern_len())
	{
		if(j == -1 || kmp.pattern[i] == kmp.pattern[j])
		{
			kmp.next[++i] = ++j;
		}else
		{
			j = kmp.next[j];
		}
	}


	//kmp;

	i = 0;
	j = 0;

	while(i < kmp.target_len())
	{
		if(j == -1 || kmp.pattern[j] == kmp.target[i])
		{
			i ++;
			j ++;
		}else{
			j = kmp.next[j];
		}

		if(j == kmp.pattern_len()){
			kmp.ans ++;
			j = 0;
		} 
	}

}
int main()
{
	while(cin>>kmp.target)
	{
		if(kmp.target[0] == '#') break;
		else cin >> kmp.pattern;
		KMP();
		printf("%d\n", kmp.ans);
	}
	return 0;
}