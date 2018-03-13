#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;

//A* 八数码问题

int idist[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char strpath[4] = {'d', 'u', 'r', 'l'};
char key[10];
int factor[10];


struct _Node{
	int val, pos;
	int f, g, h;
	
	_Node(){
	}
	_Node(int _val, int _pos, int _g, int _h)
	{
		val = _val; pos = _pos; h = _h; g = _g; f = _g + _h;
	}
	
	bool operator < (const _Node &a) const {
        return f>a.f;
    }
	
};

struct _Path{
	int from, dist;
} path[500000];
int visit[500000];
int G[500000];
stack<int> s;

int cantor()
{
	int res = 0;
	for(int i = 0; key[i]; i ++)
		for(int j = i + 1; key[j]; j ++)
			if(key[i] > key[j]) res += factor[8 - i];
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
                key[i]=j+'0'+1; if(key[i]=='9') key[i]='x';
                flag[j]=1;break;
            }
        }
    }
}


int get_h(int val)
{
   	char tmp[10];
    for(int i=0;i<=9;i++) tmp[i]=key[i];
	
    cantor_reverse(val);

    int res=0;
    for(int i=0;i<9;i++)
    {
        if(i<8) if(key[i]-'0'!=i+1) res++;
        if(i==8&&key[i]!='x') res++;
    }

    for(int i=0;i<=9;i++) key[i]=tmp[i];
    return res;
}

void Astar(int val, int pos)
{
	priority_queue<_Node> q; 
	path[val].from = path[val].dist = -1;
	visit[val] = 2;
	G[val] = 0;
	int m = get_h(val);
	q.push(_Node(val, pos, 0, m));
	while(!q.empty())
	{
		_Node x = q.top(); q.pop(); visit[val] = 2;
		cantor_reverse(x.val);
		//cout << key << endl;
		if(x.val == 0)
		{
			int t = x.val;
			while(path[t].from != -1)
			{
				s.push(path[t].dist);
				t = path[t].from;
			}
			return; 
		}
		
		int a = x.pos/3, b = x.pos%3;
		for(int i = 0; i < 4; ++i)
		{
			int dx = a + idist[i][0], dy = b + idist[i][1];
			
			if(!(dx <= 2 && dx >= 0 && dy <= 2 && dy >= 0)) continue;
			
			int curpos = dx * 3 + dy;		
			swap(key[curpos], key[x.pos]);
			int curkey = cantor();
			swap(key[curpos], key[x.pos]);
			if(visit[curkey] == 0 || (visit[curkey] == 1 && x.g + 1 < G[curkey]) )
			{
				visit[curkey] = 1; G[curkey] = x.g + 1;
				path[curkey].from = x.val; path[curkey].dist = i;
				q.push(_Node(curkey, curpos, x.g + 1, get_h(val)));
			}
		}
	}
}

void INIT()
{
	memset(visit, 0, sizeof(visit));
	memset(G, -1, sizeof(G));
	factor[0] = 1;
	for(int i = 1; i <= 8; ++i) factor[i] = factor[i - 1]*i;
}

int main()
{
	char op[10];
	while(scanf("%s", op) != EOF)
	{
		INIT();
		key[0] = op[0];
		int position = 0;
		for(int i = 1; i <= 8; ++i)
		{
			scanf("%s", op);
			key[i] = op[0];
			if(key[i] == 'x') position = i;
		}
		
		int num = 0;
		for(int i = 0; i < 9; ++i)
		{
			if(key[i] == 'x') continue;
			for(int j = 0; j < i; ++j)
			{
				if(key[j] == 'x') continue;
				if(key[i] < key[j]) num++;
			}
		}
		if(num %2 == 1) printf("unsolvable\n");
		else{
			Astar(cantor(), position);
			while(!s.empty()) printf("%c", strpath[s.top()]), s.pop();
			printf("\n");
		}
	}
	return 0;
}