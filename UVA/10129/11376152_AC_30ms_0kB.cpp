#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

const int maxn = 30;
int G[maxn], in[maxn], out[maxn];
bool visit[maxn];
int numin, numout,root;
bool flag, flag1;
char key[1010];

void init()
{
	for(int i = 1; i < maxn; ++i)
	{
		G[i] = i;
	}
	memset(visit, false, sizeof(visit));
	memset(in, 0, sizeof(in));
	memset(out, 0, sizeof(out));
	numin = 0;
	numout = 0;
	root = 0;
	flag = flag1 = true;
}
int find(int p)
{
	return p == G[p] ? p : find(G[p]);
}

void Union(int x, int y)
{
	int r1 = find(x);
	int r2 = find(y);
	
	if(r1 != r2) G[r2] = r1;
}
int main()
{
	int n, t;
	
	cin >> t;
	while(t--)
	{
		cin >> n;
		init();
		for(int i = 1; i <= n; ++i)
		{
			cin >> key;
			int len = strlen(key);
			int start = key[0] - 'a' + 1;
			int end = key[len - 1] - 'a' + 1;
			
			visit[start] = visit[end] = true;
			
			out[start] ++;
			in[end] ++;
			Union(start, end);
		}
		
		
		for(int i = 1; i < maxn; ++i)
		{
			if(visit[i])
			{
				if(G[i] == i)
				{
					root ++;
				}
				
				if(in[i] != out[i])
				{
					if(in[i] == out[i] + 1)
					{
						numin ++;
					}else if(out[i] == in[i] + 1)
					{
						numout ++;
					}else
					{
						flag = false;
						break;
					}
				}
			}
			if(root > 1)
			{
				flag = false;
				break;
			}
		}
		
        if((flag && numin == 0 && numout == 0 && flag1) || (flag && numin == 1 && numout == 1 && flag1))
			 printf("Ordering is possible.\n");
        else
            printf("The door cannot be opened.\n");
		
	}
	return 0;
}