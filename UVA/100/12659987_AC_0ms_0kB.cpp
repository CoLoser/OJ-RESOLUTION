#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 1000000;
int Table[MAXN+1];

int getTable(int rhs)
{
	if(rhs <= MAXN && Table[rhs]) return Table[rhs];
	int count = (rhs % 2 == 0 ? (1 + getTable(rhs / 2)) : (1 + getTable(rhs*3 + 1)));
	if(rhs <= MAXN) Table[rhs] = count;
	return count;
}

int main()
{
	memset(Table, 0, sizeof(Table));
	Table[1] = 1;
	
	int a, b;
	while(cin >> a >> b)
	{
		cout << a <<" "<< b <<" ";
		if(a > b) swap(a, b);
		int MAX = -1, t;
		for(int i = a; i <= b; ++i) t = getTable(i), MAX = max(MAX, t);
		cout << MAX <<endl; 
	}
	return 0;
}