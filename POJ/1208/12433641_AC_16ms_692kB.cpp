#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 27;

const char MOVE[] = "move";
const char PILE[] = "pile";
const char OVER[] = "over";
const char ONTO[] = "onto";
const char QUIT[] = "quit";
vector<int> Stack[MAXN];
char cmd1[100], cmd2[100];
struct _Position{
	int stack;
	int pos;
	_Position(int s, int p):pos(p), stack(s){
	}
};
void init()
{
	for(int i = 0; i < MAXN; ++i)Stack[i].clear(), Stack[i].push_back(i);
}

void Print(int n)
{
	for(int i = 0; i < n; ++i)
	{
		int len = Stack[i].size();
		printf("%d:", i);

  		if(len != 0)
		{
			for(int j = 0; j < len; ++j)
			{
				printf(" %d", Stack[i][j]);
			}
  		}
		printf("\n");
	}
}

_Position findBlock(int n, int x)
{
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < Stack[i].size(); ++j)
			if(x == Stack[i][j]) return _Position(i, j);
}

void move(_Position pa, _Position pb, char cmd2[])
{
	//cout << pa.stack << "--" << pa.pos <<endl;
	vector<int>::iterator itas = Stack[pa.stack].begin(), itbs = Stack[pb.stack].begin();
	vector<int>::iterator itae = Stack[pa.stack].end(), itbe = Stack[pb.stack].end();
	if(strcmp(cmd2, ONTO) == 0)
	{
		Stack[pb.stack].insert(itbs + pb.pos + 1, Stack[pa.stack][pa.pos]);
	}else{
		Stack[pb.stack].push_back(Stack[pa.stack][pa.pos]);
	}
	Stack[pa.stack].erase(itas + pa.pos, itas + pa.pos + 1);
}

void pile(_Position pa, _Position pb, char cmd2[])
{
	//cout << pa.stack << "--" << pa.pos <<endl;
	vector<int>::iterator itas = Stack[pa.stack].begin(), itbs = Stack[pb.stack].begin();
	vector<int>::iterator itae = Stack[pa.stack].end(), itbe = Stack[pb.stack].end();
	if(strcmp(cmd2, ONTO) == 0)
	{
		Stack[pb.stack].insert(itbs + pb.pos, itas + pa.pos, itae);
	}else{
		Stack[pb.stack].insert(itbe, itas + pa.pos, itae);
	}
	Stack[pa.stack].erase(itas + pa.pos, itae);
}


int main()
{
	int n, a, b;
	while(cin >> n)
	{
		init();
		while(cin >> cmd1)
		{
			if(strcmp(cmd1, QUIT) == 0) break;
			cin >> a >> cmd2 >> b;
			_Position pa = findBlock(n, a);
			_Position pb = findBlock(n, b);
			if(pa.stack == pb.stack) continue;
			
			if(strcmp(cmd1, MOVE) == 0) move(pa, pb, cmd2);
			else pile(pa, pb, cmd2);
		}
		Print(n);
	}
	return 0;
}