#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>
using namespace std;

int idist[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char strdist[10]={'u','d','l','r'};
int factor[10];
stack<int> result;
char str[100];

struct _Node{
	int val, pos;
	_Node(){
	}
	_Node(int _val, int _pos)
	{
		val = _val;
		pos = _pos;
	}
};
bool visit[400000];
struct _Path{
	int from, dist;
	
	_Path(){
	}
}path[400000];

int cantor()
{
	int res = 0;
	for(int i = 0; str[i]; i ++)
		for(int j = i + 1; str[j]; j ++)
			if(str[i] > str[j]) res += factor[8 - i];
	return res;
}

void cantor_reverse(int val)
{
	int tmp[10], flag[10];
    memset(flag,0,sizeof(flag));
    for(int i = 0; i < 9; i++) tmp[i]=val/factor[8-i],val=val%factor[8-i];
    for(int i = 0; i < 9; i++)
    {
        int num=0;
        for(int j=0;j<9;j++)
        {
            if(flag[j]==0) num++;
            if(num==tmp[i]+1)
            {
                str[i]=j+'0'+1; if(str[i]=='9') str[i]='x';
                flag[j]=1;break;
            }
        }
    }
}

void bfs(int val, int pos)
{
	queue<_Node> q;
	q.push(_Node(val, pos));
	visit[val] = 1; path[val].from = -1; path[val].dist = -1; 
	
	while(!q.empty())
	{
		_Node x = q.front();
		q.pop();
		
		if(x.val == 0)
		{
			//cout << "---" <<endl;
			int cur = x.val;
			//cout << cur << endl;
			while(1)
			{
				//cout << path[cur].from << endl;
				if(path[cur].from == -1) break;
				result.push(path[cur].dist);
				cur = path[cur].from;
			}
			return;
		}
		
		int a = x.pos/3, b = x.pos%3;
		cantor_reverse(x.val);
		//cout << str<<endl;
		for(int i = 0; i < 4; ++i)
		{
			int dx = a + idist[i][0], dy = b + idist[i][1];
			
			if(!(dx < 3 && dx >= 0 && dy < 3 && dy >= 0)) continue;
					
			int curpos = dx * 3 + dy;
			
			swap(str[curpos], str[x.pos]);
			
			int tmp = cantor();
			
			if(visit[tmp])
			{
				swap(str[curpos], str[x.pos]);
				continue;
			}
				
			path[tmp].from = x.val;
			path[tmp].dist = i;
			visit[tmp] = 1;
			
			q.push(_Node(tmp, curpos));
			swap(str[curpos], str[x.pos]);
		}
	}
	return ;
 } 
int main()
{
	factor[0] = 1; for(int i = 1; i <= 8; ++i) factor[i] = i * factor[i - 1];
	char option[100];
	while(scanf("%s", option) != EOF)
	{
		str[0] = option[0];
		int position = 0;
		
		for(int i = 1; i <= 8; ++i)
		{
			scanf("%s", option);
			str[i] = option[0];
			if(option[0] == 'x') position = i;
		}
		
		int tmp = 0;
		
		for(int i = 0; str[i]; ++i)
		{
			//cout << str[i] << endl;
			for(int j = 0; j < i; ++j)
			{
				if(str[j] == 'x') continue;
				if(str[i] < str[j]) tmp ++;
			}
		}
		
		if(tmp % 2 == 1) cout << "unsolvable\n";
		
		int t = cantor(); 
		memset(visit, 0, sizeof(visit));
		bfs(t, position);
		
		while(!result.empty()) 
		{
			printf("%c", strdist[result.top()]);
			result.pop(); 
		}
		cout << endl;
		//cout << "----" << endl;
	}
	return 0;
 } 