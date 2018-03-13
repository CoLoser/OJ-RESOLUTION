#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;


char Start = 'b';
char END = 'm';
const int MAXN = 1050;
bool flag;
bool visit[MAXN];
char End[MAXN];
char start[MAXN];
int n;

void dfs(char c)
{
	if(c == END){
		flag = true;
		return;
	}

	for(int i = 0; i < n; ++i)
	{
		if(flag) break;
		
		if(!visit[i] && start[i] == c)
		{
			visit[i] = 1;
			dfs(End[i]);
			visit[i] = 0;
		}
	}
}

int main()
{
	char c;
	while((c = getchar()) != EOF) {
        n = 0;
        for(;;) {
            start[n] = End[n] = c;
            if(start[n] == '0') {
                getchar();
                break;
            }
            while((c=getchar()) != '\n')
                End[n] = c;
            n++;
            c = getchar();
        }

        flag = 0;
        memset(visit, 0, sizeof(visit));
        if(n > 0)
            dfs(Start);

        // 输出结果
        if(flag)
            printf("Yes.\n");
        else
            printf("No.\n");
	}
	return 0;
}