#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n, m;
	int a[999];
	while(scanf("%d%d", &n, &m) != EOF){
		bool flag = true;
		int idx = 0;
		for(int i = n; i <= m; ++i){
			int ans = 0;
			int t = i;
			int x;
			while(t != 0){
				x = t%10;
				t /= 10;
				ans += x*x*x;
			}
			
			if(ans == i){
				a[idx ++] = i;
				flag = false;
			}
		}
		if(flag) printf("no\n");
		else{
			for(int i = 0; i < idx; ++i)
				printf("%d%c", a[i], i == idx - 1 ? '\n' : ' ');
		}
	}
	return 0;
}